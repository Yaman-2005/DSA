import requests
from bs4 import BeautifulSoup
import csv

def convertCountry(cc):
    response = requests.get("https://www.iban.com/country-codes")
    soup = BeautifulSoup(response.content,'html.parser')
    l2 = soup.find_all('td')
    i = 0
    j = 1
    while i < len(l2):
        names = str(l2[i].text)
        codes = str(l2[j].text)
        if cc.upper() == codes:
            return names
        if cc == 'en':
            return 'England'
        if cc == 'un':
            return 'United Nations'

        i=i+4
        j=j+4



def getdata(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 0
    while ini < ratlengthAPAC:
        sorted_ratingsAPAC.append(float(raw_dataAPAC[ini].text))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getacs(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    rawacs = soup.find_all('td', attrs= {'class':"mod-color-sq mod-acs"})
    raw_names = soup.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    acs = []
    sorted_names = []
    dict = {}
    for item1,item2 in zip(raw_names, rawacs):
        dict[item1.text] = float(item2.text)
    return dict


def getKD(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 2
    while ini < ratlengthAPAC:
        sorted_ratingsAPAC.append(float(raw_dataAPAC[ini].text))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getKAST(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 3
    while ini < ratlengthAPAC:
        st = raw_dataAPAC[ini].text
        st = st.replace('%', '')
        sorted_ratingsAPAC.append((float(st) / 100.0))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getADR(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 4
    while ini < ratlengthAPAC:
        sorted_ratingsAPAC.append(float(raw_dataAPAC[ini].text))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getKPR(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 5
    while ini < ratlengthAPAC:
        sorted_ratingsAPAC.append(float(raw_dataAPAC[ini].text))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getAPR(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 6
    while ini < ratlengthAPAC:
        sorted_ratingsAPAC.append(float(raw_dataAPAC[ini].text))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getFKPR(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 7
    while ini < ratlengthAPAC:
        sorted_ratingsAPAC.append(float(raw_dataAPAC[ini].text))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getFDPR(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 8
    while ini < ratlengthAPAC:
        sorted_ratingsAPAC.append(float(raw_dataAPAC[ini].text))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getHS(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 9
    while ini < ratlengthAPAC:
        if raw_dataAPAC[ini].text == "":
            sorted_ratingsAPAC.append(0)
        else:
            st = raw_dataAPAC[ini].text
            st = st.replace('%','')
            sorted_ratingsAPAC.append((float(st)/100.0))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def getCL(url):
    responseAPAC = requests.get(url)
    soupAPAC = BeautifulSoup(responseAPAC.content, 'html.parser')
    raw_namesAPAC = soupAPAC.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    raw_dataAPAC = soupAPAC.find_all('td', attrs={'class': "mod-color-sq"})
    sorted_ratingsAPAC = []
    sorted_namesAPAC = []
    dicto = {}
    ratlengthAPAC = len(raw_dataAPAC)
    namlengthAPAC = len(raw_namesAPAC)
    ini = 10
    while ini < ratlengthAPAC:
        if raw_dataAPAC[ini].text == "":
            sorted_ratingsAPAC.append(0)
        else:
            st = raw_dataAPAC[ini].text
            st = st.replace('%','')
            sorted_ratingsAPAC.append((float(st)/100.0))
        ini = ini + 11
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    ln = len(sorted_namesAPAC)
    lc = len(sorted_ratingsAPAC)
    for i1, i2 in zip(range(ln), range(lc)):
        dicto[sorted_namesAPAC[i1]] = sorted_ratingsAPAC[i2]
    return dicto


def Merge(dict1, dict2):
    return dict1.update(dict2)


def getAgents(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    raw = soup.find_all('td', attrs={'class': "mod-agents"})
    raw_namesAPAC = soup.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    sorted_namesAPAC = []
    dicto = {}
    namlengthAPAC = len(raw_namesAPAC)
    i = 0
    while i < namlengthAPAC:
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    i = 0
    while i < len(raw):
        pure = raw[i].find_all('img')
        j = 0
        AGL = []
        while j < len(pure):
            purestr = str(pure[j])
            l = purestr.find('/')
            check = purestr[l:]
            l = check.find('/')
            check = check[l:]
            final = check[21:]
            l1 = final.find('.')
            final1 = final[:l1]
            AGL.append(final1)
            j = j+1
        dicto[sorted_namesAPAC[i]] = AGL
        i = i+1
    return dicto

def getCountry(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    flag = soup.find_all('i', attrs={'class':'flag'})
    raw_namesAPAC = soup.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    sorted_namesAPAC = []
    dicto = {}
    i = 0
    flagslist = []
    while i < len(raw_namesAPAC):
        sorted_namesAPAC.append(raw_namesAPAC[i].text)
        i = i + 1
    i = 1
    while i < len(flag):
        flagstr = str(flag[i])
        flagstr1 = flagstr[19:21]
        flagslist.append(convertCountry(flagstr1))
        i=i+1
    for item1,item2 in zip(range(len(sorted_namesAPAC)), range(len(flagslist))):
        dicto[sorted_namesAPAC[item1]] = flagslist[item2]
    return dicto


def sort_csv(input_filename, output_filename, sort_column, ascending=True, delimiter=',', has_header=True):
    # Read input CSV
    with open(input_filename, 'r', newline='', encoding='utf-8') as infile:
        reader = csv.reader(infile, delimiter=delimiter)
        rows = list(reader)

    # Separate header and data
    header = None
    data_rows = rows
    if has_header:
        if not rows:
            raise ValueError("CSV file is empty but has_header is True")
        header = rows[0]
        data_rows = rows[1:]

    # Determine column index
    if has_header:
        try:
            col_index = header.index(sort_column)
        except ValueError:
            raise ValueError(f"Column '{sort_column}' not found in header")
    else:
        if not isinstance(sort_column, int):
            raise TypeError("sort_column must be integer when has_header=False")
        col_index = sort_column

    # Validate column index
    for i, row in enumerate(data_rows):
        if col_index >= len(row):
            raise IndexError(f"Row {i + 1} has only {len(row)} columns (index {col_index} requested)")

    # Sort data
    try:
        sorted_data = sorted(data_rows,
                             key=lambda x: x[col_index],
                             reverse=not ascending)
    except IndexError as e:
        raise IndexError(f"Invalid column index {col_index}") from e

    # Write output CSV
    with open(output_filename, 'w', newline='', encoding='utf-8') as outfile:
        writer = csv.writer(outfile, delimiter=delimiter)
        if header:
            writer.writerow(header)
        writer.writerows(sorted_data)

def getRND(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    rawacs = soup.find_all('td', attrs= {'class':"mod-rnd"})
    raw_names = soup.find_all('div', attrs={'style': "font-weight: 700; margin-bottom: 2px; width: 90px;"})
    acs = []
    sorted_names = []
    dict = {}
    for item1,item2 in zip(raw_names, rawacs):
        dict[item1.text] = float(item2.text)
    return dict