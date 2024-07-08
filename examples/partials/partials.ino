#include <Ministache.h>

/***************************************************
  This is an example of how to use Mustache partials with the Ministache library
 (https://github.com/floatplane/ministache).

  For more details on Mustache syntax, see http://mustache.github.io/mustache.5.html
 ****************************************************/

void setup() {
  Serial.begin(115200);
  Serial.println("");

  // Create a JsonDocument instance to hold the data that we'll use in our template
  const char* json = R"""(
  {
    "people": [
      {
        "name": "Alice",
        "role": "Engineer"
      },
      {
        "name": "Bob",
        "role": "Intern"
      }
    ]
  }
  )""";
  JsonDocument data;
  deserializeJson(data, json);

  // Create a template that renders the data for a single person. This is a *partial*.
  auto personTemplate = "Name: {{name}}\tRole: {{role}}\n";

  // Create a template that renders the data for all people. This is the main template.
  // Note that it loops over a data field called "people", and includes the partial "person" for each of
  // them.
  auto reportTemplate = R"""(
    People report:
    {{#people}}
      {{> person}}
    {{/people}}
  )""";

  // Render the template with the data. The third argument is the partials list. This
  // defines how to map a partial reference like "person" to a particular template
  // ("personString").
  ministache::PartialList partials = {{"person", personTemplate}};
  auto output = ministache::render(reportTemplate, data, partials);

  // Print the result
  Serial.println(output);

  // Expected output:
  //
  // People report:
  // Name: Alice  Role: Engineer
  // Name: Bob    Role: Intern
}

void loop() {
  delay(500);
}
