from scrape import getdata, sort_csv, getRND
from scrape import getacs
from scrape import Merge
from scrape import getKD
from scrape import getCL
from scrape import getHS
from scrape import getAPR
from scrape import getFDPR
from scrape import getKPR
from scrape import getADR
from scrape import getFKPR
from scrape import getKAST
from scrape import getAgents
from scrape import getCountry
from collections import OrderedDict
import csv

urlAPAC = 'https://www.vlr.gg/event/stats/2379/champions-tour-2025-pacific-stage-1'
urlEMEA = 'https://www.vlr.gg/event/stats/2380/champions-tour-2025-emea-stage-1'
urlAMR = 'https://www.vlr.gg/event/stats/2347/champions-tour-2025-americas-stage-1'
dictPAC = getdata(urlAPAC)
dictEU = getdata(urlEMEA)
dictAMR = getdata(urlAMR)
acsPAC = getacs(urlAPAC)
acsEU = getacs(urlEMEA)
acsAMR = getacs(urlAMR)
kdPAC = getKD(urlAPAC)
kdEU = getKD(urlEMEA)
kdAMR = getKD(urlAMR)
clPAC = getCL(urlAPAC)
clEU = getCL(urlEMEA)
clAMR = getCL(urlAMR)
hsPAC = getHS(urlAPAC)
hsEU = getHS(urlEMEA)
hsAMR = getHS(urlAMR)
aprPAC = getAPR(urlAPAC)
aprEU = getAPR(urlEMEA)
aprAMR = getAPR(urlAMR)
fdprPAC = getFDPR(urlAPAC)
fdprEU = getFDPR(urlEMEA)
fdprAMR = getFDPR(urlAMR)
kprPAC = getKPR(urlAPAC)
kprEU = getKPR(urlEMEA)
kprAMR = getKPR(urlAMR)
adrPAC = getADR(urlAPAC)
adrEU = getADR(urlEMEA)
adrAMR = getADR(urlAMR)
fkprPAC = getFKPR(urlAPAC)
fkprEU = getFKPR(urlEMEA)
fkprAMR = getFKPR(urlAMR)
kastPAC = getKAST(urlAPAC)
kastEU = getKAST(urlEMEA)
kastAMR = getKAST(urlAMR)
agentsPAC = getAgents(urlAPAC)
agentsEU = getAgents(urlEMEA)
agentsAMR = getAgents(urlAMR)
countryPAC = getCountry(urlAPAC)
countryEU = getCountry(urlEMEA)
countryAMr = getCountry(urlAMR)
rndPAC = getRND(urlAPAC)
rndEU = getRND(urlEMEA)
rndAMR = getRND(urlAMR)
Merge(acsPAC, acsEU)
Merge(acsPAC, acsAMR)
Merge(dictPAC, dictEU)
Merge(dictPAC, dictAMR)
Merge(clPAC, clEU)
Merge(clPAC, clAMR)
Merge(hsPAC, hsEU)
Merge(hsPAC, hsAMR)
Merge(aprPAC, aprEU)
Merge(aprPAC, aprAMR)
Merge(fdprPAC, fdprEU)
Merge(fdprPAC, fdprAMR)
Merge(kdPAC, kdEU)
Merge(kdPAC, kdAMR)
Merge(adrPAC, adrEU)
Merge(adrPAC, adrAMR)
Merge(fkprPAC, fkprEU)
Merge(fkprPAC, fkprAMR)
Merge(kastPAC, kastEU)
Merge(kastPAC, kastAMR)
Merge(kprPAC,kprEU)
Merge(kprPAC,kprAMR)
Merge(agentsPAC,agentsEU)
Merge(agentsPAC,agentsAMR)
Merge(countryPAC,countryEU)
Merge(countryPAC,countryAMr)
Merge(rndPAC, rndEU)
Merge(rndPAC, rndAMR)
sorted_dictacs = OrderedDict(sorted(acsPAC.items()))
sorted_dictrating = OrderedDict(sorted(dictPAC.items()))
sorted_dictKD = OrderedDict(sorted(kdPAC.items()))
sorted_dictcl = OrderedDict(sorted(clPAC.items()))
sorted_dictKPR = OrderedDict(sorted(kprPAC.items()))
sorted_dictKAST = OrderedDict(sorted(kastPAC.items()))
sorted_dictADR = OrderedDict(sorted(adrPAC.items()))
sorted_dictFKPR = OrderedDict(sorted(fkprPAC.items()))
sorted_dictFDPR = OrderedDict(sorted(fdprPAC.items()))
sorted_dictAPR = OrderedDict(sorted(aprPAC.items()))
sorted_dictHS = OrderedDict(sorted(hsPAC.items()))
sorted_dictAgents = OrderedDict(sorted(agentsPAC.items()))
sorted_dictCountry = OrderedDict(sorted(countryPAC.items()))
sorted_dictRND = OrderedDict(sorted(rndPAC.items()))
field_names = ['PLAYER','RATING','ACS','K:D','CL','KPR','KAST','ADR','FKPR','FDPR','APR','HS','AGENTS','COUNTRY','ROUND']
with open('VCT Global Ratings.csv', 'w') as csv_file:
    writer = csv.writer(csv_file)
    writer.writerow(field_names)
    for key1, key2,key3,key4,key5,key6,key7,key8,key9,key10,key11,key12,key13,key14 in zip(sorted_dictrating.items(),sorted_dictacs.items(),sorted_dictKD.items(),sorted_dictcl.items(),sorted_dictKPR.items(),sorted_dictKAST.items(),sorted_dictADR.items(),
                            sorted_dictFKPR.items(),sorted_dictFDPR.items(),sorted_dictAPR.items(),sorted_dictHS.items(),sorted_dictAgents.items(),sorted_dictCountry.items(),sorted_dictRND.items()):
           writer.writerow([key1[0],key1[1],key2[1],key3[1],key4[1],key5[1],key6[1],key7[1],key8[1],key9[1],key10[1],key11[1],key12[1],key13[1],key14[1]])
sort_csv('VCT Global Ratings.csv','VCT Global Ratings.csv','RATING',ascending=False)
print('data scraped to file')


