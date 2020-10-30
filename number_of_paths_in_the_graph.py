#coding: utf-8
print('Введите вершины графов:')
v=input().split()
print('Введите вершину-начало графа:')
first=input()
print('Введите вершину-конец графа:')
end=input()
print('Введите вершину, относительно которой будут производиться подсчет количества путей:')
un=input()
print('Введите звенья графа, направленные от A к B, в формате AB:')
rs=input().split()
froms,tos,counts={i:set() for i in v},{i:set() for i in v},{i:set() for i in v}
for i in rs:
    froms[i[0]].add(i[1])
    tos[i[1]].add(i[0])
counts[first]=set(first)
while len(tos):
    d=[]
    for i in tos.keys():
        if len(tos[i])==0:
            for j in froms[i]:
                for k in counts[i]:
                    counts[j].add(k+i)
                tos[j].discard(i)
            d.append(i)
    for i in d:
        tos.pop(i)
print('Всего путей:',len(counts[end]))
ans=[un in i for i in counts[end]]
while False in ans:
    ans.pop(ans.index(False))
print('Путей, проходящих через вершину ',un,':',len(ans))
print('Путей, не проходящий через вершину ',un,':',len(counts[end])-len(ans))