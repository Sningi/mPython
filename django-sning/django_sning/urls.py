"""django_sning URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, re_path
from gp import views as gp_views
urlpatterns = [
    path('', gp_views.redirect_view),
    path(r'gp/', gp_views.index_hander),
    path(r'gp/put-message', gp_views.connect_hander),
    path(r'gp/collect', gp_views.collect_hander),
    path(r'gp/getitem.html', gp_views.get_item_hander),
    re_path(r'gp/search.*\.html', gp_views.search_hander),
    re_path(r'gp/items.*\.html', gp_views.items_hander),
    re_path(r'gp/item-.+\.html', gp_views.item_detail_hander),
    re_path(r'gp/.+\.html', gp_views.html_hander),
    path(r'admin/', admin.site.urls),
    # path(r'', admin.site.urls),
]
