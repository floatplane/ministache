#include <ministache.hpp>

/***************************************************
  This is a very basic example for the ministache library
 (https://github.com/floatplane/ministache).

  It shows how the library can be used to render a Mustache template with a JSON object.

  For more details on Mustache syntax, see http://mustache.github.io/mustache.5.html
 ****************************************************/

void setup() {
  Serial.begin(115200);
  Serial.println("");

  // Create a JSON object to hold the data that we'll use in our template. It looks like this:
  // {
  //   "Alice": {
  //     "name": "Alice",
  //     "role": "Engineer"
  //   },
  //   "Bob": {
  //     "name": "Bob",
  //     "role": "Intern"
  //   }
  // }
  JsonDocument data;
  auto people = data["people"].to<JsonArray>();
  auto alice = people.add<JsonObject>();
  alice["name"] = "Alice";
  alice["role"] = "Engineer";
  auto bob = people.add<JsonObject>();
  bob["name"] = "Bob";
  bob["role"] = "Intern";

  // Create a template string that renders the data for a single person. This is a partial.
  String personString = "Name: {{name}}\tRole: {{role}}\n";

  // Create a template string that renders the data for all people. This is the main template.
  String reportString = "People report:\n{{#people}}{{> person}}{{/people}}";

  // Render the template with the data. The third argument is the partials list. This
  // defines how to map a partial reference like {{>person }} to a particular template (personString).
  String output = ministache::render(reportString, data, {{"person", personString}});

  // Print the result
  Serial.println(output);
  // People report:
  // Name: Alice  Role: Engineer
  // Name: Bob    Role: Intern
}

void loop() {
  delay(500);
}
