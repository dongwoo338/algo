from django.contrib import admin
from .models import Coffee
# Register your models here.
# model을 admin과 연동을 해서 관리할 수 있다.

admin.site.register(Coffee)