import threading
import pymysql as Mysql
from datetime import datetime
"""
@author: sning
createtime: 2019-04-10
updatetime: 2019-04-10
mark: 隔离数据操作
"""


def synchronized(func):
    # 线程锁
    func.__lock__ = threading.Lock()

    def lock_func(*args, **kwargs):
        with func.__lock__:
            return func(*args, **kwargs)
    return lock_func


class DBHelper(object):
    # 单例的DBHelper
    instance = None
    con = None
    cur = None

    @synchronized
    def __new__(cls, *args, **kwargs):
        """
        :type kwargs: object
        """
        if cls.instance is None:
            cls.instance = super().__new__(cls)
        return cls.instance

    def __init__(self):
        if self.con == None:
            self.con = Mysql.connect(
                host='127.0.0.1',
                user='sning',
                passwd='197010',
                db='gp')
            self.cur = self.con.cursor()

    # 生成器，协程：将商品数据写入数据库
    def saveJingDongItem(self):
        counter = 0
        while True:
            platform_id, name, price, shopname, platform, good_percent, image_url = yield
            createtime = datetime.now()
            # print(platform_id, name, price, shopname, platform, good_percent)
            cmd = "Insert into item values(0,'%s','%s','%s','%s','%s','%s',0,'%s',0,'%s'); " % (
                platform_id, name, price, shopname, createtime, platform, good_percent, image_url)
            try:
                if self.itemExisted(platform_id):
                    counter += 1
                    print("第%s条商品信息已存在:%s %s" % (counter, platform_id, name))
                else:
                    self.cur.execute(cmd)
                    self.con.commit()
                    counter += 1
                    print("第%d条商品信息保存成功:%s %s" % (counter, platform_id, name))
            except Exception as e:
                print("Insert item error:", e)

    # 生成器，协程：将评论数据写入数据库
    def saveJingDongComment(self):
        counter = 0
        while True:
            comment = yield
            cmd = "Insert into jdcomment values(%d,%d,'%s','%s',%d,'%s',%d,%d,'%s'); " % (
                comment[0], comment[1], Mysql.escape_string(
                    comment[2]), comment[3], comment[4],
                comment[5], comment[6], comment[7], comment[8])
            try:
                self.cur.execute(cmd)
                self.con.commit()
                counter += 1
                # print("第%d条保存成功:%s %s" % (counter, comment[3], comment[2]))
            except Exception as e:
                print("Insert comment error:", e)

    def itemExisted(self, platform_id):
        # 判断是否已经抓取商品
        return self.cur.execute("select platform_id from item where platform_id=%s" % platform_id)

    def itemSpiderFinish(self, platform_id):
        self.cur.execute(
            "select finish from item where platform_id=%s" % platform_id)
        data = self.cur.fetchone()
        if data[0] > 0:
            return True
        return False

    def getCommentsById(self, platform_id):
        # 获取某商品全部评论
        cmd = "select content,createtime,score,userlevel,isMobile,client from jdcomment where item_pid=%d" % platform_id
        self.cur.execute(cmd)
        return self.cur.fetchall()

    def getAllId(self):
        # 获取商品ID列表
        cmd = "select platform_id from item where finish>0"
        self.cur.execute(cmd)
        return self.cur.fetchall()

    def getSpideFinishIds(self):
        # 获取抓取完成的商品ID列表
        cmd = "select platform_id from item where finish=1"
        self.cur.execute(cmd)
        return self.cur.fetchall()

    def getAnalyseFinishIds(self):
        # 获取抓取完成的商品ID列表
        cmd = "select platform_id from item where finish=2"
        self.cur.execute(cmd)
        return self.cur.fetchall()

    def deleteItem(self, platform_id):
        cmd = "delete from item where platform_id=%s" % platform_id
        self.cur.execute(cmd)
        self.con.commit()
        print('删除商品ID:%s 的相关信息' % platform_id)

    def deleteInvalidItem(self):
        ids = self.getSpideFinishIds()
        count = 0
        print('清理无效商品及其评论中...')
        for mid in ids:
            if len(self.getCommentsById(mid)) < 400:
                self.deleteItem(mid[0])
                count += 1
        print('本次共计删除%d条无效商品' % count)

    def getItemById(self, platform_id):
        cmd = 'select * from item where platform_id=%d' % platform_id
        self.cur.execute(cmd)
        return self.cur.fetchone()

    def setSpiderFinish(self, platform_id):
        cmd = 'update item set finish=1 where platform_id=%s' % platform_id
        self.cur.execute(cmd)
        self.con.commit()

    def setAnalyseFinish(self, platform_id):
        length = len(self.getCommentsById(platform_id))
        cmd = 'update item set finish=2,comments=%d where platform_id=%s' % (
            length, platform_id)
        self.cur.execute(cmd)
        self.con.commit()

    def setDjangoFinish(self, platform_id):
        cmd = 'update item set finish=3 where platform_id=%s' % platform_id
        self.cur.execute(cmd)
        self.con.commit()

    def getCommentsLen(self):
        cmd = 'select count(*) from jdcomment'
        self.cur.execute(cmd)
        return self.cur.fetchone()[0]


if __name__ == '__main__':
    dbHelper = DBHelper()
    print(dbHelper.getCommentsLen())
