#include <WiFi.h>
#include <DHT.h>
#include <Adafruit_SSD1306.h>
#include <ThingSpeak.h>

// Define pins
#define SOIL_MOISTURE_PIN 34
#define LDR_PIN 35
#define DHT_PIN 32
#define BUZZER_PIN 25

// OLED display setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT sensor setup
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak credentials
unsigned long channelID = YOUR_CHANNEL_ID;
const char* apiKey = "YOUR_API_KEY";

// Variables
int soilMoistureValue = 0;
int lightIntensityValue = 0;
float temperatureValue = 0;
float humidityValue = 0;

WiFiClient client;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize sensors
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  dht.begin();

  // Initialize OLED display
  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Smart Expressive Pot");
  display.display();
  delay(2000);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read sensor data
  soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  lightIntensityValue = analogRead(LDR_PIN);
  temperatureValue = dht.readTemperature();
  humidityValue = dht.readHumidity();

  // Display sensor data on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Moisture: ");
  display.println(soilMoistureValue);
  display.print("Light: ");
  display.println(lightIntensityValue);
  display.print("Temp: ");
  display.println(temperatureValue);
  display.print("Humidity: ");
  display.println(humidityValue);
  display.display();

  // Display emoji based on conditions
  if (soilMoistureValue < 2000) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("I'm thirsty! :(");
    display.display();
    tone(BUZZER_PIN, 1000, 500); // Buzzer alert
  } else if (lightIntensityValue < 1000) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("I need light! :|");
    display.display();
  } else {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("I'm happy! :)");
    display.display();
  }

  // Send data to ThingSpeak
  ThingSpeak.setField(1, soilMoistureValue);
  ThingSpeak.setField(2, lightIntensityValue);
  ThingSpeak.setField(3, temperatureValue);
  ThingSpeak.setField(4, humidityValue);
  ThingSpeak.writeFields(channelID, apiKey);

  // Wait before next reading
  delay(10000);
}
