import sys
import os
import django
sys.path.append('/home/sning/myfile/mproject/django_sning')
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'django_sning.settings')
django.setup()
from gp.models import FinishItem
from sDBHelper import DBHelper
from datetime import datetime


def processOne(platform_id):
    dbHelper = DBHelper()
    length = len(dbHelper.getCommentsById(platform_id))
    item = dbHelper.getItemById(platform_id)
    try:
        FinishItem.objects.create(
            platform_id=item[1],
            name=item[2],
            price=item[3],
            shop_name=item[4],
            analyse_time=datetime.now(),
            paltform=item[6],
            comments=length,
            good_percent=item[8],
            image_url=item[10])
    except Exception:
        print('item already existed')


def moveAll():
    # 数据迁移
    dbHelper = DBHelper()
    ids = dbHelper.getAnalyseFinishIds()
    count = 0
    for cid in ids:
        count += 1
        print('迁移第%d件商品%d' % (count, cid[0]))
        processOne(cid[0])
        dbHelper.setDjangoFinish(cid)


def delete_all():
    items = FinishItem.objects.all()
    for item in items:
        item.delete()


if __name__ == '__main__':
    moveAll()
