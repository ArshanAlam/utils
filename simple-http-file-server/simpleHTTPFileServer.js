/**
 * Author:  Arshan Alam
 *
 * Date:    20161105
 *
 * A simple HTTP server for serving files.
 *
 * I wrote this server for doing 'localhost' web development.
 *
 * Some HTML5 (and JS) features require the webpage to be served over
 * an SSL (HTTPS) connection, or development be done on localhost.
 *
 * Sadly, I can't do development on 'file:// ... '
 */

// process.argv[0] = Path to Node.js binary
// process.argv[1] = Path to executing file (this file)
// process.argv[2 ...] Command line arguments
var projectDir = process.argv[2] || process.cwd();
var port = process.argv[3] || 8080;

var http = require("http");
var fs = require("fs");
var url = require("url");

var server = http.createServer((request, response) => {
  var pathname = url.parse(request.url).pathname.toString().trim();
  if (pathname == "/") {
    pathname += "index.html";
  }
  var filename = projectDir + pathname;

  fs.stat(filename, (err, stat) => {
    if (err) {
      response.statusCode = 404;
      response.write("File not found");
      response.end();
    } else {
      response.writeHead(200);
      fs.createReadStream(filename).pipe(response);
    }
  });
});

server.listen(port, () => {
  console.log("Server is listening on port "
    + port + " for project " + projectDir);
    process.on("exit", () => {
      server.close();
    });
});
