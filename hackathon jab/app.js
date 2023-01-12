const express = require('express');
const mongoose = require('mongoose');
const myroutes  = require('./routes/query');
const connectDB = require('./db/dbconnect');
const path = require('path');


const app = express();
app.set('view engine', 'ejs');
app.set('views', 'views');

app.use(express.json());
app.use(express.urlencoded({extended:false}));
app.use(express.static(path.join(__dirname, 'public')));




const serverstart = async()=>{

    try {
       await connectDB(process.env.MONGODB_URI);
       app.listen(process.env.port || 5000,()=>{
        console.log("listening the port ");
    })  
    } catch (error) {
        console.log(error)
    }
}
    serverstart();
    

app.use(myroutes);




