with open(file="parse\\save2.txt", encoding="utf8") as http:
    http = http.read()
    a, _, *b, c,  d, e= http.split('\n')
    print("a is " + a)
    print("c is " + c)
    print("d is " + d)
    print("e is " + e)
    print("? is " + _)
    print("b is " + d)
    # request, *headers, _, _, body = http.split('\n')
    # method, path, protocol = request.split(' ')
    # headers = dict(
    #     line.split(': ', maxsplit=1)
    #     for line in headers
    # )
    # print(headers)