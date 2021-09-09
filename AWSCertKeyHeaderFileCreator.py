headerList = ['#ifndef myCertificateData\n',
              '#define myCertificateData\n',
             '\n',
             '/*\n',
             ' * you can add any root ca file\n',
             ' */\n',
             'const char AmazonRootCA[] = \n',
             '\n',
             '/*\n',
             ' * Key can be downloaded during the creation of that certificate\n',
             ' */\n',
             'const char AWSprivateKey[] = \n',
             '\n',
             '/*\n',
             ' * Certficate attatched to your thing in AWS IoT\n',
             ' */\n',
             'const char AWScertificate[] = \n',
             '\n',
             '#endif\n']
#=============================================================================
def stringLineEditor(s):
    z = '"'+s+'\\n" \\ \n'
    return z

def headerCertInput(z):
    lst=[]
    fx = open(z,"r")
    while(1):
        s = fx.readline()
        if s == "":
            fx.close()
            break
        lst.append(stringLineEditor(s[:-1]))
    res = "".join(lst)
    res = res[:-4] + ';'
    return res

#res = headerCertInput("AmazonRootCA1.pem")
#print(res)
#============================================================================

import os
os.chdir(".\\certificates")
l = os.listdir()
requiredCert = ['CA1.pem', 'certificate.pem.crt', 'private.pem.key']
nameOfCert = []
for x in l:
    for y in requiredCert:
        if x.find(y)>0:
            nameOfCert.append(x)

os.chdir("..")

dirList = ['AmazonRootCA', 'AWScertificate','AWSprivateKey']

f = open('myCertificateData.h','a')
singleWrite = False
for line in headerList:
    for x in range(len(dirList)):
        if line.find(dirList[x])>0:
            res = headerCertInput("certificates\\"+nameOfCert[x])
            f.write(line[:-1]+res+'\n')
            singleWrite = True
            break
    
    if not singleWrite :
        f.write(line)
    singleWrite = False

f.close()

