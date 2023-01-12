const express = require('express');
const mongoose = require('mongoose');

const query_schema = mongoose.Schema({

    soil_type:{
        type:String,
        require :[true,"soil type must be provided"]
    },
    Nitrogen_level:{
        type: Number,
        require: [true,"nutrient level must be provided"]
    }
    ,
    potassium_level:{
        type: Number,
        require: [true,"nutrient level must be provided"]
    }
    ,
    phosphorous_level:{
        type: Number,
        require: [true,"nutrient level must be provided"]
    }
    ,
    humidity_level:{
        type: Number,
        require: [true,"humidity level must be provided"]
    }
    ,
    choice:{
        type: String,
        require: [true,"choice must be provided"]
    },
    month:{
        type: String,
       require: [true,"month should be provided"]
    },
    cropname:{
        type:String,
        require : [true,"crop name must be provided"]

    },
    description:{
        type: String,
        require :[true,"description must be provided"]
    },
    imageurl:{
        type: String,
        require: [true,"image must be provided"]
    }

})


const query_model = mongoose.model('farmer_query',query_schema);

module.exports =query_model;