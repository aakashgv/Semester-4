import sys
import string

class namtab:
	"""docstring for name"""
	def __init__(self,name,start,end=-1):
		self.name = name
		self.start = start
		self.end = end

class argtab:
	"""docstring for name"""
	def __init__(self,arg1,arg2):
		self.arg1=[]
		self.arg2=[]

	def add(self,arg1,arg2):
		self.arg1.append(str(arg1))
		self.arg2.append(str(arg2))

#-----------------------------------------------------------------------------------------------------------------

def getline():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global start
	global arg
	global found
	global progcnt
	global dict

	if(expanding==1):
		line=deftab[progcnt[0]]
		progcnt[0]+=1

	else:
		line=file.readline()
		if(line==""):
			return

#-----------------------------------------------------------------------------------------------------------------

def processline():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict

	#print("inside process")
	string=line.split()
	found=-1
	i=0

	while(i<len(n1)):
		try:
			found=string.index(n1[i].name)
			break
		except ValueError:
			found=-1
			i+=1

	if(string[0]==r"%macro" or string[0]==r"%define"):
		define()

	elif(string[0]==r"%assign"):
		if(string[2].isdigit()):
			dict[string[1]]=string[2]
		else:
			dict[string[1]]=str(calculate())

	elif(found!=-1):
		expanding=1
		expand(i)

	else:
		print(line)

#-----------------------------------------------------------------------------------------------------------------

def calculate():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict

	string=line.split()
	temp=string[2]
	temp=temp.split()
	temp="".join(temp)
	if(temp.find("+")!=-1):
		temp=temp.split("+")
		temp=" + ".join(temp)

	elif(temp.find("-")!=-1):
		temp=temp.split("-")
		temp=" - ".join(temp)

	for j in dict.keys():
		sp=temp.split()
		if(j in sp):
			temp1=temp
			temp1=temp1.replace(j,dict[j])
			temp=temp1

	temp=temp.split()
	j=2
	sum=0
	while(j<=len(temp)):
		if(temp[j-1]=="+"):
			sum=int(temp[j-2])+int(temp[j])
		elif(temp[j-1]=="-"):
			sum=int(temp[j-2])-int(temp[j])
		temp.pop(0)
		temp.pop(0)
		temp[0]=sum
		j=2
	return sum

#-----------------------------------------------------------------------------------------------------------------

def expand(i):
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict
	global labelno

	arg.insert(0,argtab(0,0))
	createarg(i)
	print(";",end="")
	print(line)
	start=n1[i].start
	progcnt.insert(0,start)
	end=n1[i].end-1
	label=[]
	label1=[]
	find=-1

	if(deftab[progcnt[0]-1].split()[0]==r"%define"):
		temp=line.split()
		getline()
		sub()
		t3=[]
		t3.extend(temp[:found])
		t3.append(line)
		t3.extend(temp[found+1:])
		temp=" ".join(t3)
		print(temp)
		arg.pop(0)
		progcnt.pop(0)
		if(not len(arg)):
			expanding=0
		return

	while(progcnt[0] < end):
		getline()
		sub()
		if(line.split()[0]==r"%if"):
			callif()
			continue
		if(line.split()[0]==r"%rep"):
			callloop()
			continue
		if(line.split()[0][0]=="#" and line.split()[0][-1]==":"):
			labelno+=1
			label.insert(0,line.split()[0][:-1])
			label1.insert(0,'#' + str(labelno) + line.split()[0][1:-1])
			print(label1[0],"".join(line.split()[1:]))
			continue

		j=0
		string=line.split()
		while(j<len(label)):
			
			try:
				find=string.index(label[j])
				break
			except ValueError:
				find=-1
				j+=1

		if(find!=-1):
			temp=[]
			temp.extend(string[:find])
			temp.append(label1[j])
			temp.extend(string[find+1:])
			line=" ".join(temp)
			print(line)
			continue

		processline()

	arg.pop(0)
	progcnt.pop(0)
	if(not len(arg)):
		expanding=0

#-----------------------------------------------------------------------------------------------------------------

def callloop():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict
	global loopcnt

	string=line.split()
	n=int(string[1])
	temp=[]
	getline()
	sub()
	while(line.split()[0]!=r"%endrep"):
		temp.append(line)
		getline()

	while(n>0):	
		loopcnt=0
		while(loopcnt<len(temp)):
			getloopline(temp)
			#line=temp[j]
			sub()

			if(line.split()[0]==r"%if"):
				callloopif(temp)
				if(line.split()[0]==r"%exitrep"):
					return

			elif(line.split()[0]==r"%exitrep"):
				print(line)
				return

			else:
				processline()
			loopcnt+=1
		n-=1

#-----------------------------------------------------------------------------------------------------------------

def getloopline(temp):
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict
	global loopcnt

	line=temp[loopcnt]

#-----------------------------------------------------------------------------------------------------------------

def callloopif(temp):
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict
	global loopcnt

	if(condition()):
		loopcnt+=1
		getloopline(temp)
		sub()
		while(line.split()[0] != r"%endif" and line.split()[0] != r"%elif" and line.split()[0] != r"%else"):
			if(line.split()[0]==r"%if"):
				callloopif(temp)
				loopcnt+=1
				getloopline(temp)
				sub()
				continue

			elif(line.split()[0]==r"%exitrep"):
				return

			else:
				processline()
			loopcnt+=1
			getloopline(temp)
			sub()
		while(line.split()[0]!=r"%endif"):
			loopcnt+=1
			getloopline(temp)
		return

	level=1
	while(level>0):
		if(line.split()[0]==r"%elif" and condition()):
			loopcnt+=1
			getloopline(temp)
			sub()
			while(line.split()[0] != r"%endif" and line.split()[0] != r"%elif" and line.split()[0] != r"%else"):
				if(line.split()[0]==r"%if"):
					callloopif(temp)
					loopcnt+=1
					getloopline(temp)
					sub()
					continue
				else:
					processline()
					if(line.split()[0]==r"%mend"):
						loopcnt+=1
						getloopline(temp)
						sub()
				loopcnt+=1
				getloopline(temp)
				sub()
			while(line.split()[0]!=r"%endif"):
				loopcnt+=1
				getloopline(temp)
			return

		else:
			loopcnt+=1
			getloopline(temp)
			skiploop(temp)

			if(line.split()[0]==r"%endif"):
				return
			if(line.split()[0]==r"%else"):
				loopcnt+=1
				getloopline(temp)
				sub()
				while(line.split()[0]!=r"%endif"):
					if(line.split()[0]==r"%if"):
						callloopif(temp)
					else:
						processline()
					loopcnt+=1
					getloopline(temp)
					sub()
				return

#-----------------------------------------------------------------------------------------------------------------

def skiploop(temp):
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict
	global loopcnt

	level=1
	while(level>0):
		if(line.split()[0]==r"%if"):
			level+=1
		elif(line.split()[0]==r"%endif" and level>1):
			level-=1
		elif(line.split()[0]==r"%elif" and level==1):
			return
		elif(line.split()[0]==r"%else" and level==1):
			return
		elif(line.split()[0]==r"%endif" and level==1):
			return
		loopcnt+=1
		getloopline(temp)

#-----------------------------------------------------------------------------------------------------------------

def callif():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict

	if(condition()):
		getline()
		sub()
		while(line.split()[0] != r"%endif" and line.split()[0] != r"%elif" and line.split()[0] != r"%else"):
			if(line.split()[0]==r"%if"):
				callif()
				getline()
				sub()
				continue
			else:
				processline()
			getline()
			sub()
		while(line.split()[0]!=r"%endif"):
			getline()
		return

	level=1
	while(level>0):
		if(line.split()[0]==r"%elif" and condition()):
			getline()
			sub()
			while(line.split()[0] != r"%endif" and line.split()[0] != r"%elif" and line.split()[0] != r"%else"):
				if(line.split()[0]==r"%if"):
					callif()
					getline()
					sub()
					continue
				else:
					processline()
					if(line.split()[0]==r"%mend"):
						getline()
						sub()
				getline()
				sub()
			while(line.split()[0]!=r"%sendif"):
				getline()
			return

		else:
			getline()
			skip()
			if(line.split()[0]==r"%endif"):
				return
			if(line.split()[0]==r"%else"):
				getline()
				sub()
				while(line.split()[0]!=r"%endif"):
					if(line.split()[0]==r"%if"):
						callif()
					else:
						processline()
					getline()
					sub()
				return

#-----------------------------------------------------------------------------------------------------------------

def skip():
	level=1
	while(level>0):
		if(line.split()[0]==r"%if"):
			level+=1
		elif(line.split()[0]==r"%endif" and level>1):
			level-=1
		elif(line.split()[0]==r"%elif" and level==1):
			return
		elif(line.split()[0]==r"%else" and level==1):
			return
		elif(line.split()[0]==r"%endif" and level==1):
			return
		getline()

#-----------------------------------------------------------------------------------------------------------------

def condition():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict

	string=line.split()
	if(string[2]=="EQ" and string[1]==string[3]):
		return 1

	elif(string[2]=="LE" and string[1]<=string[3]):
		return 1

	elif(string[2]=="LT" and string[1]<string[3]):
		return 1

	elif(string[2]=="GE" and string[1]>=string[3]):
		return 1

	elif(string[2]=="GT" and string[1]>string[3]):
		return 1

	elif(string[2]=="NE" and string[1]!=string[3]):
		return 1

	else:
		return 0

#-----------------------------------------------------------------------------------------------------------------

def sub():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict

	if(line.find("$")==-1):
		return

	if(line.split()[0]!=r"%assign"):
		for j in dict.keys():
			sp=line.split()
			if(j in sp):
				temp=line
				temp=temp.replace(j,dict[j])
				line=temp

	string=list(line)
	retj=0

	while(line[retj:].find("$")!=-1):
		j=retj
		word=[]
		ws=-1
		while(j<len(string)):
			if(string[j]=="$"):
				ws=j

			elif(j+1!=len(string) and not string[j+1].isalnum() and ws!=-1):
				temp=string[:ws]
				word="".join(string[ws:j+1])
				try:
					f=arg[0].arg1.index(word)
				except ValueError:
					retj=j+1
					break
				temp.extend(arg[0].arg2[f])
				temp.extend(string[j+1:])
				string=temp
				line="".join(string)
				string=list(line)
				retj=0
				break

			elif(string[j]=="-" and string[j+1]==">" and ws!=-1):
				temp=string[:ws]
				word="".join(string[ws:j])
				try:
					f=arg[0].arg1.index(word)
				except ValueError:
					retj=j+2
					break				
				temp.extend(arg[0].arg2[f])
				temp.extend(string[j+2:])
				string=temp
				line="".join(string)
				string=list(line)
				break

			elif(j+1==len(string) and ws!=-1):
				temp=string[:ws]
				word="".join(string[ws:])
				try:
					f=arg[0].arg1.index(word)
				except ValueError:
					retj=j+1
					break	
				temp.extend(arg[0].arg2[f])
				string=temp
				line="".join(string)
				string=list(line)
				break
			j+=1

#-----------------------------------------------------------------------------------------------------------------

def createarg(i):
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict

	string=deftab[n1[i].start-1]
	temp=string
	string=string.split()
	ch=line.split()
	t2=line
	if(string[0]==r"%macro" and len(string)>2):
		string="".join(string[2:])
		t2="".join(ch[found+1:])

	elif(string[0]==r"%define" and temp.find("$")!=-1):
		find=string[2].find(")")
		string="".join(string[2][:find])
		string=string.strip("(")
		t2="".join(ch[found+1:])
		find=t2.find(")")
		t2=t2[:find]
		t2=t2.strip("(")

	else:
		return

	temp=string
	string=string.split(",")
	ch=t2.split(",")

	#default arguments
	j=0
	while(j<len(string)):
		find=string[j].find("=")
		if(find!=-1):
			arg[0].add(string[j][:find],string[j][find+1:])
		else:
			arg[0].add(string[j],string[j])
		j+=1

	#positional arguments
	find1=ch[0].find("=")
	k=0
	while(k<len(ch) and find1==-1):
		if(ch[k]):
			arg[0].arg2[k]=ch[k]
		k+=1

	#reference arguments
	k=0
	while(k<len(ch) and find1!=-1):
		find1=ch[k].find("=")
		j=0
		while(j<len(arg[0].arg1)):
			find2=arg[0].arg1.index(ch[k][:find1])
			arg[0].arg2[find2]=ch[k][find1+1:]
			j+=1
		k+=1

#-----------------------------------------------------------------------------------------------------------------

def define():
	global line
	global defline
	global deftab
	global n1
	global expanding
	global arg
	global found
	global progcnt
	global dict

	#print("inside define")
	defline+=1
	string=line.split()
	
	if(string[0]==r"%define"):
		n1.append(namtab(string[1],defline,defline+2))
		if(string[2][0]=="("):
			find=line.find(")")
			deftab.append(line[:find+1])
			deftab.append(line[find+2:])
		else:
			deftab.append(" ".join(string[:2]))
			string=" ".join(string[2:])
			deftab.append(string)
		deftab.append(";end of define")
		return

	n1.append(namtab(string[1],defline,))
	deftab.append(line)
	level=1
	while(level>0):
		getline()
		line=line.strip("\n")
		line=line.strip("\t")
		line=line.strip()
		if(not line):
			continue
		deftab.append(line)
		defline+=1
		string=line.split()
		if(string[0]==r"%macro"):
			level+=1
		elif(string[0]==r"%mend"):
			level-=1
	n1[len(n1)-1].end=defline

#-----------------------------------------------------------------------------------------------------------------

file=open("input.txt","r")
para=file.readlines()
file.seek(0)
expanding=0
defline=0
found=-1
deftab=[]
n1=[]
arg=[]
start=-1
end=-1
progcnt=[]
dict={}
loopcnt=0
labelno=0

i=0
l2=-1

while(i < len(para)):
	getline()
	line=line.strip("\n")
	line=line.strip("\t")
	line=line.strip()
	if(not line):
		print()
		i+=1
		continue
	processline()
	i+=1