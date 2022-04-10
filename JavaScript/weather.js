function GeoOk(position){
    const lat = position.coords.latitude;
    const lng = position.coords.longitude;
    console.log("You live in", lat, lng);
}

function GeoFail(){
    alert("Can't find you!");
}

navigator.geolocation.getCurrentPosition(GeoOk, GeoFail);