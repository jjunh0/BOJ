// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let input = [];
	for await (const line of rl) {
		input.push(line);
		rl.close();
	}
	let a = parseInt(input[0].split(' ')[0]);
	let b = parseInt(input[0].split(' ')[1]);
	let d = parseInt(input[1]);
	for(let i = 1; i <= d; i ++) {
		if(i%2) {
			b += parseInt(a/2) + a%2;
			a = parseInt(a/2);
		} 
		else {
		 a += parseInt(b/2) + b%2;
		 b = parseInt(b/2);
		}
		
	}
	console.log(a + ' ' + b);
	process.exit();
})();
