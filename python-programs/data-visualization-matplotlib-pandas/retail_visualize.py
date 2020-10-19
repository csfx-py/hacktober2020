import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

if __name__ == '__main__':
    retail_csv = pd.read_csv("BigMartSalesData.csv")

    # 1. Plot Total Sales Per Month for Year 2011. How the total sales have increased over months in Year 2011.

    df = retail_csv.query("Year == 2011").filter(["Month", "Quantity"]).groupby(["Month"], as_index=False).sum()

    x = df["Month"]
    y = df["Quantity"]
    plt.plot(x, y)
    plt.grid()
    plt.xlabel("Month")
    plt.ylabel("Sales quantity")
    plt.title("Month vs quantity sales year 2011")
    plt.show()
    # Which month has lowest Sales ? -> february

    # 2. Plot Total Sales Per Month for Year 2011 as Bar Chart

    plt.bar(x, y)
    plt.grid()
    plt.xlabel("Month")
    plt.ylabel("Sales quantity")
    plt.title("Month vs quantity sales year 2011 in bar chart")
    plt.show()
    # Enhancement to show the value of the bar
    plt.xlabel("Month")
    plt.ylabel("Sales quantity")
    plt.title("Month vs quantity sales year 2011 in bar chart #Enhancement ")
    plt.barh(x,y)
    for index,value in enumerate(y):
        plt.text(value, index, str(value))

    plt.show()

    # Is Bar Chart Better to visualize than Simple Plot? -> yes

    # 3.  Plot Pie Chart for Year 2011 Country Wise.

    df_pie = retail_csv.query("Year == 2011").filter(["Country", "Quantity"]).groupby(["Country"], as_index=False).sum()

    Country_list = df_pie["Country"].tolist()
    quantity_list = df_pie["Quantity"].tolist()

    # for making exploding graph logic. Can also be done in list comprehension
    expod_tup = []
    count_max = max(quantity_list)
    for i in quantity_list:
        if i == count_max:
            i = i / 100000000
            expod_tup.append(i)
        else:
            i = 0
            expod_tup.append(i)
    print(expod_tup)
    explode = tuple(expod_tup)

    # Country contributes highest towards sales shown exploded

    plt.figure(figsize=(30, 8))
    plt.pie(quantity_list, labels=Country_list, autopct='%1.1f%%', explode=explode)
    plt.show()

    # Enhancement on implementing parameters shadow=True, startangle=90
    plt.pie(quantity_list, labels=Country_list, autopct='%1.1f%%', explode=explode, shadow=True,startangle=90)
    plt.show()

    # 4. Plot Scatter Plot for the invoice amounts and see the concentration of amount.

    df_scatter = retail_csv.filter(["InvoiceDate", "Amount"]).groupby(["InvoiceDate"], as_index=False).sum()
    xa = df_scatter['InvoiceDate']
    xb = df_scatter['Amount']
    plt.scatter(xa, xb)
    plt.ylim(20000, 50000)
    plt.show()

    # Enhancement to change colour of the scatter
    plt.scatter(xa, xb,c="red")
    plt.show()
