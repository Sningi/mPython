import openpyxl
import os

from muitls import gen_months

excel_path = './excel/'


def rd_month(year, month):
    filename = excel_path + \
        "t_{0}{1}.xlsx".format(year, '%2s' % (str(month).zfill(2)))
    if os.path.exists(filename):
        mexcel = openpyxl.load_workbook(filename)
        assert len(mexcel._sheets) == 5
        sheet5 = mexcel._sheets[4]
        table_name = sheet5["A1"].internal_value
        assert "表5" in table_name and \
            str(year) in table_name and \
            str(month) in table_name

        citys = []
        for row in sheet5.iter_rows():
            if isinstance(row[0], openpyxl.cell.cell.Cell) and row[0].row > 3:
                city = (row[0].internal_value).strip(
                    " ").replace("　", '').replace(" ", "")
                citys.append(city)
        # print(citys)
        # for i in range(5, 76):


def main():
    for month in gen_months('201501', '201501'):
        rd_month(month[0], month[1])


if __name__ == "__main__":
    main()
