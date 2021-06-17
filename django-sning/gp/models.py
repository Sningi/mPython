from django.db import models


class FinishItem(models.Model):
    platform_id = models.BigIntegerField(unique=True, default=0)
    name = models.CharField(max_length=255)
    price = models.IntegerField(default=0)
    shop_name = models.CharField(max_length=25)
    analyse_time = models.DateTimeField(auto_now_add=True)
    paltform = models.CharField(max_length=4)
    comments = models.IntegerField(default=0)
    good_percent = models.FloatField(default=0)
    image_url = models.CharField(
        max_length=255, default='static/images/item/example.jpg')
