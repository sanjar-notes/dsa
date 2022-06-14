import os
folders = list(filter(lambda i: i.endswith('.txt') and not os.path.isdir(i), os.listdir()))
count = 0
for f in folders:
    newname = str(count:=count+1)+f[1:]
    os.rename(f, newname)
