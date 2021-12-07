#!/usr/bin/node
const request = require('request');
const process = require('process');
const id = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + id;
request({url: url}, (err1, res, body) => {
	const n = [];
	const js = JSON.parse(body);
	js.characters.forEach(urls => {
		const id = url.split('/')[5];
		requ({url: url}, (err2, res, body) => {
			const js1 = JSON.parse(body);
			n[id] = js1.name;
		});
	});
	setTimeout(function (){
		js.characters.forEach(elem => {
			const id = elem.split('/')[5];
			console.log(n[id]);
		});
	}, 1000);
});
