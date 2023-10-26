watchySettings settings{
    .cityID = "",
    .weatherAPIKey = "",
    .weatherURL = "http://api.openweathermap.org/data/2.5/weather?id=",
    .weatherUnit = "metric",
    .weatherLang = "en",
    .weatherUpdateInterval = 30,

    .timezone = "Europe/Paris", // using 'ip' instead will automatically use the correct TZ

    .alarmHour = 7,
    .alarmMinute = 20, // will buzz at 07:20
    .bedTimeHour = 23,
    .bedTimeMinute = 45, // will go to sleep at 23:45

    .wifiSsid = "ssid",
    .wifiPassword = "password"
};
