import matplotlib.pyplot as plt
import mysql.connector
from mysql.connector import Error
# Pie chart, where the slices will be ordered and plotted counter-clockwise:

connection = mysql.connector.connect(host='localhost',
                                         database='repertoire',
                                         user='USERNAME',
                                         password='PASSWORD')
cursor = connection.cursor()

req1 = "SELECT COUNT(nom) FROM personne WHERE relation='ami'"
cursor.execute(req1)
result1 =cursor.fetchone()[0]

req2 = "SELECT COUNT(nom) FROM personne WHERE relation='famille'"
cursor.execute(req2)
result2 = cursor.fetchone()[0]

req3 = "SELECT COUNT(nom) FROM personne WHERE relation='professionnel'"
cursor.execute(req3)
result3 =cursor.fetchone()[0]

req4 = "SELECT COUNT(nom) FROM personne WHERE relation='eglise'"
cursor.execute(req4)
result4 =cursor.fetchone()[0]

req5 = "SELECT COUNT(nom) FROM personne WHERE relation='autre'"
cursor.execute(req5)
result5 =cursor.fetchone()[0]
 

labels = 'ami', 'famille','professionnel','eglise' ,'autre'
sizes = [result1,result2,result3, result4, result5]
            # only "explode" the 2nd slice (i.e. 'Hogs')
explode = (0, 0.1, 0, 0, 0)

fig1, ax1 = plt.subplots()
ax1.pie(sizes, explode=explode, labels=labels, autopct='%1.1f%%',
                    shadow=True, startangle=90)
            # Equal aspect ratio ensures that pie is drawn as a circle.
ax1.axis('equal')

plt.show()

cursor.close()
connection.close()


import matplotlib
matplotlib.axes.Axes.pie
matplotlib.pyplot.pie
