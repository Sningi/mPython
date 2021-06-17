from django.shortcuts import render, redirect
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from gp import models
from django.http import HttpResponse
from sPlatformJingDong import getItem, getPageItems
from sProcessComments import AnalyseAll, AnalyseOne
from cmd import moveAll
from multiprocessing import Process


def get_recent():
    return models.FinishItem.objects.order_by('-analyse_time')[:4]


def index_hander(request):
    data = 0
    # index页面
    return render(request, 'index.html', locals())


def pItem(item_id):
    item_id = int(item_id)
    print("多进程开启处理商品采集与分析")
    getItem(item_id)
    AnalyseOne(item_id)
    moveAll()


def pCate(cate):
    print('多进程开启处理批量商品采集与分析')
    getPageItems(cate)


def collect_hander(request):
    data = 0
    try:
        item_id = request.GET["item"]
        t = Process(target=pItem, args=(item_id,))
        t.start()
        # 多线程开启处理商品采集与分析
        data = 1
    except Exception as e:
        print("item is None:", e)
    try:
        # 多线程开启处理批量商品采集与分析
        cate_id = request.GET["cate"]
        t = Process(target=pCate, args=(cate_id,))
        t.start()
        data = 2
    except Exception as e:
        print("cate is None:", e)
    # index页面
    return render(request, 'index.html', locals())


def connect_hander(request):
    name = request.GET["name"]
    email = request.GET["email"]
    subject = request.GET["subject"]
    phone = request.GET["phone"]
    message = request.GET["message"]
    with open('log/contact.txt', 'a+') as file:
        file.writelines('----start----\nname:%s\nemail:%s\nsubject:%s\nphone:%s\nmessage:%s\n-----end-----\n\n' % (
            name, email, subject, phone, message))
    # index页面
    return render(request, 'contact.html')


def html_hander(request):
    # html页面
    return render(request, request.path[4:])


def redirect_view(request):
    # 重定向
    response = redirect('/gp')
    return response


def search_hander(request):
    itemlist = models.FinishItem.objects.all()
    dlen = len(itemlist)

    Keyword = request.GET["Keyword"]
    page = 1
    recent_list = get_recent()
    if len(request.path) > 15:
        page = int(request.path[10:-5])
    paginator = Paginator(
        models.FinishItem.objects.filter(name__contains=Keyword), 10)
    items = paginator.page(page)
    # 总页码数
    pagecount = paginator.num_pages
    prev_pager = 1
    # 上一页
    if page > 1:
        prev_pager = page - 1
    next_pager = pagecount
    if page < pagecount:
        # 下一页
        next_pager = page + 1
    # html页面
    isSearch = 1
    return render(request, 'items.html', locals())


def items_hander(request):
    itemlist = models.FinishItem.objects.all()
    dlen = len(itemlist)

    isSearch = 0
    page = 1
    recent_list = get_recent()
    if len(request.path) > 14:
        page = int(request.path[9:-5])
    paginator = Paginator(itemlist, 10)
    items = paginator.page(page)
    # 总页码数
    pagecount = paginator.num_pages
    prev_pager = 1
    # 上一页
    if page > 1:
        prev_pager = page - 1
    next_pager = pagecount
    if page < pagecount:
        # 下一页
        next_pager = page + 1
    # html页面
    return render(request, 'items.html', locals())


def item_detail_hander(request):
    itemlist = models.FinishItem.objects.all()
    dlen = len(itemlist)

    item = models.FinishItem.objects.get(platform_id=request.path[9:-5])
    recent_list = get_recent()
    # html页面
    return render(request, 'item-details.html', locals())


def get_item_hander(request):
    itemlist = models.FinishItem.objects.all()
    dlen = len(itemlist)

    id = request.GET["id"]
    try:
        item = models.FinishItem.objects.get(platform_id=id)
    except:
        return render(request, '404.html')
    recent_list = get_recent()
    # html页面
    return render(request, 'item-details.html', locals())
