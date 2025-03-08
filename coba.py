import random

isi = ''''''

namas = [
    'Ari',
    'Adi',
    'Budi',
    'Buono',
    'Dodi',
    'Dito',
    'Tuti',
    'Gunowo'
]

for i in range(3):
    for j in range(len(namas)):
        isi += f"""{namas[j]} {random.randint(1,40)}\n"""#{round(random.random()*4,2)}\n"""

print(isi)

with open('no1.txt','w') as f:
    f.write(isi)


