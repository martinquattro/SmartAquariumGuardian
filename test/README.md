# Unit tests

Tests are organized under `test/`, with one directory per module or
hardware-independent component.

## Run the tests

From the project root, run:

```bash
pio test -e test_native
```

This environment builds and runs tests on the host computer. It does not upload
firmware to the ESP32 or change the `prod` environment.

To run a single suite, filter by its directory name:

```bash
pio test -e test_native -f test_datetime
```

## Add tests for another module

Create a directory whose name starts with `test_`, then add a test source file.
For example:

```text
test/
├── README.md
├── framework/common_defs.h
├── include/config.h
├── src/core/base/driver.h
├── test_datetime/
│   └── test_datetime.cpp
├── test_json_parser/
│   ├── lib/nlohmann_json/json.hpp
│   └── test_json_parser.cpp
├── test_temperature_sensor/
│   └── test_temperature_sensor.cpp
└── test_tds_sensor/
    └── test_tds_sensor.cpp
```

Test functions use the `test_` prefix and Unity assertions. Register each test
with `RUN_TEST` in its suite's `main` function. Tests can include project
headers using a relative path.

Add source files from `src/` to `build_src_filter` in `[env:test_native]` when
they are needed by the tests. For hardware-dependent drivers, provide
test-only substitutes for the hardware interfaces and override an input method
to feed deterministic values to the real driver logic.

`DateTime` has its source file listed in the native environment. The JSON
payload parser is header-only; its test-local support headers replace logging
macros and redirect the JSON include without pulling in hardware dependencies.
The temperature sensor tests override the protected virtual `GetRawReading()`
method to supply controlled values without accessing the OneWire hardware.
Shared test-only headers provide the minimal hardware and driver interfaces
needed to compile the sensor on the host.

The TDS sensor tests override `GetAnalogReading()` to supply ADC voltage
samples. They exercise the driver's averaging, temperature compensation, and
voltage range handling without accessing the ADC hardware.
