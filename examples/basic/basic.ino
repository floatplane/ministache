#include <Ministache.h>

/***************************************************
  This is a very basic example for the ministache library
 (https://github.com/floatplane/ministache).

  It shows how the library can be used to render a Mustache template with a JSON object.

  For more details on Mustache syntax, see http://mustache.github.io/mustache.5.html
 ****************************************************/

void setup() {
  Serial.begin(115200);
  Serial.println("");

  // Create a JSON object to hold the data that we'll use in our template
  JsonDocument data;
  data["name"] = "World";
  data["value"] = 42;

  // Create a template string
  String templateString = "Hello, {{name}}! The answer is {{value}}.";

  // Render the template with the data
  String output = ministache::render(templateString, data);

  // Print the result
  Serial.println(output);  // Prints: Hello, World! The answer is 42.
}

void loop() {
  delay(500);
}
