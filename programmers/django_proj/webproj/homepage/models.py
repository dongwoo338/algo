from django.db import models

# Create your models here.
class Coffee(models.Model):
    def __str__(self):
        return self.name
    name = models.CharField(default="", max_length=30)
    price = models.IntegerField(default=0)
    is_ice = models.BooleanField(default=False)
    # Field1
    # Field2
    """
    fieldtype의 종류
    문자열 : charField
    숫자 : IntegerField, smallIntegerField, ...
    논리형 : BooleanField
    시간/날짜 : DateTimeField
    """