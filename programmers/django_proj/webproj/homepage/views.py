from django.shortcuts import HttpResponse, render
from .models import Coffee
from .forms import CoffeeForm
# Create your views here.
def index(request):
    nums =[1,2,3,4,5]
    return render(request, 'index.html', {"my_list" : nums})
    # 3번째, 사용할 인자들을 dictionary형태로 전달

def coffee_view(request):
    #...
    coffee_all = Coffee.objects.all()
    return render(request,'coffee.html',{"coffee_list" : coffee_all})  