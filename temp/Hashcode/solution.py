# cook your dish here

from collections import defaultdict as dd
from collections import OrderedDict
                    
def rollback(project,contr):
    for worker in project.get('workers'):
        contr[worker]['curr_work_at'] = ''
    project.get('to_be_upgrad').clear()
    project['workers'].clear()
    
    
def farzi_rollback(project,contr):
    for worker in project.get('workers'):
        contr[worker]['curr_work_at'] = ''


file = 'b'
file_out = file+'_out.txt'

with open(file+".txt",'r') as f:
	x = f.readline()
	
	c,p = map(int,x.split())
	contr = {}  # {name : [(skill,level)])
	skills = {}
	for i in range(c):
	    contr_name,n = f.readline().split()
	    n = int(n)
	    roles = []
	    for j in range(n):
	        skill,level = f.readline().split()
	        level = int(level)
	        if skill not in skills:
	            skills[skill] = {contr_name : level}
	        else:
	            skills[skill][contr_name] = level
	        
	    contr[contr_name] = {
	        'curr_work_at' : ''
	    }
	        
	        
	# print(contr)
	# print(skills)
	# # Projects

	projects = {}

	for i in range(p):
	    project_name, days, score, bb, role_count = f.readline().split()
	    days = int(days)
	    score = int(score)
	    bb = int(bb)
	    role_count = int(role_count)
	    roles = []
	    for j in range(role_count):
	        skill,level = f.readline().split()
	        level = int(level)
	        roles.append((skill,level))
	        
	        
	    
	    project = {
	        'name' : project_name,
	        'days' : days,
	        'score' :score,
	        'bb' : bb,
	        'role_count' :role_count,
	        'roles' :roles,
	        'workers' : [],
	        'status' : 0,# 0- not completed
	        'to_be_upgrad' : [], #(name,skill)
	        'started_at' : -1
	        
	    }
	    projects[project_name] = project



# print(projects)
####Logic######

ans = []

curr_day = 0
no_of_proj_completed = 0
temp = []
while(True):
    # TA each day check fr every project
    some_change = 0
    for proj_name,project in projects.items():
        # if project is already completed then don't do anything
        if project.get('status') == 0:
            for idx,role in enumerate(project.get('roles')):
                skill,req_level = role
                d = OrderedDict(sorted(skills[skill].items(), reverse = True,key = lambda  item : item[1]))
                for cand,lev in d.items():
                    if lev > req_level and contr[cand]['curr_work_at'] == '':
                        project.get('workers').append(cand)
                        contr[cand]['curr_work_at'] = proj_name
                        
                        break
                    elif lev == req_level and contr[cand]['curr_work_at'] == '':
                        project.get('workers').append(cand)
                        contr[cand]['curr_work_at'] = proj_name
                        project.get('to_be_upgrad').append((cand,skill))
                        
                        break
                    elif lev == req_level-1 and contr[cand]['curr_work_at'] == '':
                        flag = 0
                        for worker in project.get('workers'):
                            if worker in skills[skill] and skills[skill][worker] >= req_level:
                                project.get('workers').append(cand)
                                contr[cand]['curr_work_at'] = proj_name
                                project.get('to_be_upgrad').append((cand,skill))
                                
                                flag = 1
                                break
                        if flag == 1:
                            break
                if len(project.get('workers')) != idx+1:
                    rollback(project,contr)
                    break
        
            if len(project.get('workers')) == project.get('role_count'):
                for ele in project.get('to_be_upgrad'):
                    cand,skill = ele
                    skills[skill][cand]+=1
                some_change = 1
                project['status'] = 1
                
                
                project['started_at'] = curr_day
                last_date = project['started_at'] + project['days'] -1 
                temp.append((project,last_date))
                # rollback(project,contr)
    if len(temp) <1:
        break
    temp.sort(key = lambda item: item[1])
    if temp:
        curr_day+= temp[0][1]-curr_day
    while (temp and temp[0][1] == curr_day):
        project = temp[0][0]
        farzi_rollback(project,contr)
        ans.append(project)
        no_of_proj_completed+=1
        temp.remove((project,curr_day))
     
    # print(curr_day)
    
    print(curr_day)
    if no_of_proj_completed == p:
        break


final_ans = []
for project in ans:
    final_ans.append((project.get('name'),project.get('started_at'),project.get('bb')))
    
xyz = list(sorted(final_ans,key = lambda item : (item[1],item[2])))

# print(xyz)
with open(file_out,'w') as outfile:
	print(no_of_proj_completed)
	outfile.write(f"""{no_of_proj_completed} """ + '\n')
	for ele in final_ans:
	    print(ele[0])
	    outfile.write(f"""{ele[0]} """ + '\n')
	    print(' '.join(projects[ele[0]]['workers']))
	    outfile.write(f"""{' '.join(projects[ele[0]]['workers'])} """ + '\n')

# for ele in final_ans:
#     print(ele[0])
#     print(' '.join(projects[ele[0]]['workers']))




    
