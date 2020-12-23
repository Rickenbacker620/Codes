from django.shortcuts import render
from django.http import HttpResponse
from io import BytesIO

from .doc import Expreport

# Create your views here.
def index(request):
    a = Expreport(['1', '2', '3', '4', '5', '6', '7','8'])

    # st = bytes()
    # if request.method == 'POST':
    #     dct = request.POST
    #     print(dct)
    #     chun = request.FILES.get("ff")
    #     for line in chun.chunks():
    #         # print(line)
    #         st += line
    # print(str(st, encoding='utf-8'))
    context = {
        'paras':a.paras[:-1],
        'file':a.paras[-1]
    }
    if request.method == 'POST':
        response = HttpResponse(content_type='application/vnd.ms-word')
        response['Content-Disposition'] = 'attachment;filename='+'hello'+'.docx'
        tmp = []
        dct = request.POST
        for k,v in dct.items():
            tmp.append(v)
        tmp = tmp[1:]
        a = Expreport(tmp)

        output = BytesIO()
        a.fill_all()
        a.save(output)
        output.seek(0)
        response.write(output.getvalue())
        return response
    return render(request, "imessage.html", context)
