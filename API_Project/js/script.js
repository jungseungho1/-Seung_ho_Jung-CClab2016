function initMap() {
  var map = new google.maps.Map(document.getElementById('map'), {
    center: {lat: 36, lng: 139},
    zoom: 5
  });

  var layer = new google.maps.FusionTablesLayer({
    query: {
      select: 'location',
      from: '1xWyeuAhIFK_aED1ikkQEGmR8mINSCJO9Vq-BPQ'
    },
    heatmap: {
      enabled: true
    }
  });

  layer.setMap(map);
}


