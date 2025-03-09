


with open('no2.txt','r') as file:
    a = file.read().split('\n')

dataOrang = []

for i in a:
    now = list(i.split(' '))
    print(now)
    if len(now) == 2:
        dataOrang.append([now[0],int(now[1])])


b = sorted(dataOrang,key=lambda x: x[1],reverse=1)


print(b)
