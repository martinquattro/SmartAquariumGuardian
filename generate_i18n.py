import csv
import json
import os


INPUT_CSV = os.path.join('data', 'loc_ids.csv')

OUTPUT_JSON_DIR = os.path.join('data', 'lang')
OUTPUT_CPP_HEADER = os.path.join('src', 'framework', 'localization', 'loc_ids.h')

print("-------------------------------------------------")
print(f"  I18N AUTOMATION: Initiating generation from '{INPUT_CSV}'...")

loc_ids = []
lang_data = {}
headers = []

try:
    with open(INPUT_CSV, mode='r', encoding='utf-8-sig') as csvfile:
        reader = csv.reader(csvfile)
        try:
            headers = next(reader)
        except StopIteration:
             print(f"Error: '{INPUT_CSV}' empty.")
             exit(1)

        if len(headers) < 2 or headers[0].strip() != 'STRING_ID':
            print(f"Error: Missing headers")
            exit(1)

        lang_codes = [h.strip() for h in headers[1:]]
        for lang in lang_codes:
            lang_data[lang.lower()] = {}

        for row in reader:
            # Skip empty rows
            if not row or len(row) == 0 or not row[0].strip(): continue

            str_id = row[0].strip()
            loc_ids.append(str_id)

            # Save translations per language
            for i, lang in enumerate(lang_codes):
                translation = row[i + 1] if (i + 1) < len(row) else ""
                lang_data[lang.lower()][str_id] = translation

    print(f"  - CSV Read. Found {len(loc_ids)} IDs and {len(lang_codes)} languages: {lang_codes}")

except FileNotFoundError:
    print(f"Error: Could not found loc ids file.")
    exit(1)
except Exception as e:
    print(f"Unexpected Error: {e}")
    exit(1)

# Generate output files
if os.path.exists(OUTPUT_JSON_DIR):
    for file in os.listdir(OUTPUT_JSON_DIR):
        if file.endswith('.json'):
             os.remove(os.path.join(OUTPUT_JSON_DIR, file))
else:
    os.makedirs(OUTPUT_JSON_DIR, exist_ok=True)

for lang_code, translations in lang_data.items():
    json_path = os.path.join(OUTPUT_JSON_DIR, f'{lang_code}.json')
    with open(json_path, 'w', encoding='utf-8') as jsonfile:
        json.dump(translations, jsonfile, indent=2, ensure_ascii=False)
    print(f"  - Generated Json: {json_path}")


# Generate C++ Header
os.makedirs(os.path.dirname(OUTPUT_CPP_HEADER), exist_ok=True)

cpp_content = f"""#pragma once

// ============================================================================
//  Auto Generated File by generate_i18n.py 
//  Do not hand edit this file directly.
// ============================================================================

struct LocId 
{{
"""

for str_id in loc_ids:
    cpp_content += f'    static constexpr const char* {str_id} = "{str_id}";\n'

cpp_content += """};

"""

with open(OUTPUT_CPP_HEADER, 'w', encoding='utf-8') as cppfile:
    cppfile.write(cpp_content)

print(f"  - C++ header generated: {OUTPUT_CPP_HEADER}")
print("  I18N AUTOMATION: Success.")
print("-------------------------------------------------")