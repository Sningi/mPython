import os
import shutil 
from muitls import gen_months

months = gen_months("201001", "202101")
for m in months:
    fn = "./excel/t_"+str(m[0])+'%2s.xlsx' % (str(m[1]).zfill(2))
    if not os.path.exists(fn):
        shutil.copy("./excel/t_201901.xlsx",fn)
