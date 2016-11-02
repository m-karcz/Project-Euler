passcodes = open("../C++/txt/Problem79.txt", "r").readlines()
mydict = {};
password = "";
for line in passcodes:
  line=line[:-1]
  mydict[line[0]+line[1]]=-1
  mydict[line[1]+line[2]]=-1
  mydict[line[0]+line[2]]=-1
  mydict[line[1]+line[0]]=1
  mydict[line[2]+line[1]]=1
  mydict[line[2]+line[0]]=1
  for letter in line:
    if letter not in password:
      password+=letter
print("".join(sorted(password,cmp=lambda x,y:mydict[x+y])))
