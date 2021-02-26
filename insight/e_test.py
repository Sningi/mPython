# coding:utf-8
import jieba

'''novel = 'txt/人生若只如初见.txt'   
s=open(novel).read()
hmseg = jieba.cut(s)
seg_space = ' '.join(hmseg)'''
str1 = '战马嘶鸣的战场'
seg_list = jieba.cut(str1, cut_all=True)  # 全模式
print("$".join(seg_list))
