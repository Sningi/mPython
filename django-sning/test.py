# import time
# import random
# from multiprocessing import Process


# def piao(name):
#     print('%s piao' % name)
#     time.sleep(random.randrange(10, 20))
#     print('%s piao end' % name)


# p1 = Process(target=piao, args=('e',))  # 必须加,号
# p2 = Process(target=piao, args=('a',))
# p3 = Process(target=piao, args=('w',))
# p4 = Process(target=piao, args=('y',))

# p1.start()
# p2.start()
# p3.start()
# p4.start()
# print('主线程')

# import synonyms
from sDBHelper import DBHelper
from jieba import analyse
import jieba.posseg as pseg


def ExtractWord(wordlist):
    sentence = ','.join(wordlist)
    words = analyse.extract_tags(sentence, 5)
    wordlist = []
    for w in words:
        wordlist.append(w)
    return wordlist


def sen_str(kv_list, keyword):
    seglist = [word.flag for word in kv_list]
    # print('\n', seglist)
    for word in kv_list:
        print(word.word, end='\t')
        if len(word.flag) > 1:
            # pass
            print(word.flag, end='\t')
    if ['n', 'a'] in seglist:
        print('have ')
    # index = seglist.find('n-a')
    # print('')
    # print(index)
    return None


if __name__ == '__main__':
    dbHelper = DBHelper()
    comments = [com[0] for com in dbHelper.getCommentsById(100003671698)]
    # comtxt = '.'.join(comments)
    # result = analyse.textrank(
    #     comtxt, topK=150, withWeight=True)
    # # mdict = dict()
    # for i in result:
    #     # mdict += ' %s' % k
    #     print(i)
    # wl = ExtractWord(comments)
    # print(wl)
    # import synonyms
    # synonyms.display("口感")
    # seglist = ['n', 'ns', 'nr', 'a', 'ad', 'v', 'vn', 'b']
    # 根据词性过滤无关词
    # 标点，非语素，英语，介词，连词
    filterlist = ['w', 'x', 'eng', 'p', 'c',
                  'uj', 'ul', 'uz', 'm', 'zg', 'vg', 'vn', 'i', 'y', 'l', 'r']
    filterdict = dict.fromkeys(filterlist, True)
    # segdict = dict.fromkeys(seglist, True)
    for comment in comments:
        kv_list = list()
        words = pseg.cut(comment)
        keyword = list()
        for word in words:
            if word.flag == 'l':
                keyword.append(word.word)
            if word.flag not in filterdict:
                # print(word.word, word.flag, end='\t')
                kv_list.append(word)
        sen_str(kv_list, keyword)
        # print(comment)
