var url = "http://api.dronestre.am/data";
var request = new XMLHttpRequest();
request.open("GET", url, true);
request.addEventListener("load", function(){
  var response = JSON.parse(request.responseText);
  console.log(response);
})

var request = require('request');
var express = require('express');
var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3003);

var url = "http://api.dronestre.am/data";


app.get('/strike-list', function(req, res, next){

  var context = {};

  request(url, function(err, response, body){
    if(!err && response.statusCode < 400){
      // remove reserved word from JSON string and return as object
      var resp = JSON.parse(body.replace(/"location":/g,'"loc":'));
      var total = resp.strike.length;

          var c = []; 

      for (var i = 0; i < total; i++){
        if (resp.strike[i].country in oc(c)) {
          continue;
        } else {
          c.push(resp.strike[i].country);
        }
      }

      // make an array of country objects each having a name and array of strikes 
      context.countries = [];

      for(var i = 0; i < c.length; i++){
        var o = {'nme':c[i],'strikes':[]};
        context.countries.push(o);
      }

   for(var j = 0; j < context.countries.length; j++){
        for (var i = 0; i < total; i++){
          if (resp.strike[i].country == context.countries[j].nme){
            context.countries[j].strikes.push({
              'year':resp.strike[i].date.substring(0,4),
              'town':resp.strike[i].town,
              'loc':resp.strike[i].loc,
              'deaths':resp.strike[i].deaths,
              'civilians':resp.strike[i].civilians,
              'children':resp.strike[i].children,
              'narr':resp.strike[i].narrative,
              'lat':resp.strike[i].lat,
              'lon':resp.strike[i].lon
            });
          }
        }
      }

//       {{#each countries}}
//   <table>
//     <caption>{{this.nme}}</caption>
//     <thead>
//       <tr>
//         <th></th>
//         <th>When</th>
//         <th>Where</th>
//         <th>What</th>
//         <th>Who</th>
//       </tr>
//     </thead>
//     <tbody>
//       {{#each this.strikes}}
//         <tr>
//           <th>
//           </th>
//           <td>
//             {{year}}
//           </td>
//           <td>
//               {{town}}
//               <br>{{loc}}
//           </td>
//           <td>
//             {{narr}}
//           </td>
//           <td>
//               <strong>{{deaths}} killed</strong>
//               {{#if civilians}}
//                 <br>Civilians: {{civilians}}
//               {{/if}}
//               {{#if children}}
//               <br>Children: {{children}}
//               {{/if}}
//           </td>
//         </tr>
//       {{/each}}
//     </tbody>
//   </table>
// {{/each}}