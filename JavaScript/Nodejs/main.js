var http = require('http');

http.createServer((req,res) => {
  res.write('<head><meta charset="utf-8"/></head>');
  res.write("hello");
  res.end();
}).listen(3000);