// Run by Node.js
const readline = require('readline');

(async () => {
   let rl = readline.createInterface({ input: process.stdin, output: process.stdout });
   
   let input = [];
   for await (const line of rl) {
      input.push(line);
      rl.close();
   }
   
   let n = parseInt(input[0]);
   let ab = input[1].split(' ');
   
   let result = '';
   for (var i = 1; i <= n; i++) {
      for (var j = 1; j <= n; j++) {
         if (i % 2 == 0 || j % 2 == 0) result += ab[1];
         else result += ab[0];
         
         if (j != n) result += ' ';
      }
      console.log(result);
		 result = '';
   }
      
   process.exit();
})();
