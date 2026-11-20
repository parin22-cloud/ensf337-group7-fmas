# Group 7 – Work Split

ENSF 337 Term Project (FMAS) · Due **Saturday, November 29, 2026** · Presentations Nov 30 – Dec 4

Team: **Parin Patel**, **Agastya Parashar**, **Aditya Patel**

Each person owns one main class (design + implementation + testing), one deliverable, and tests another person's code. The heaviest class (Flight) carries the least extra paperwork, so the total load is roughly even.

---

## Who does what

### Parin Patel – Passenger + main menu
| Area | Tasks |
|---|---|
| Code | `Passenger.h` / `Passenger.cpp` (done) |
| Code | `main.cpp`: title screen (group number + names), "Press Return" pauses, 8-option menu loop, tracking the selected flight, handling bad input (letters instead of numbers, no flight selected yet, out-of-range choices) |
| Code | Prompts for options 5–7 (add passenger, remove passenger, save Y/N) that call the Flight/Airline functions |
| Deliverable | `README.txt` with exact compile + run commands for **Windows and macOS** (tested on both) |
| Testing | Tests **Aditya's** Airline code (loading, saving, `findFlight`) |
| Branch | `feature/passenger`, `feature/main-menu` |

### Agastya Parashar – Flight
| Area | Tasks |
|---|---|
| Code | `Flight.h` / `Flight.cpp`: constructor, getters |
| Code | `displaySeatMap()` using `vector<vector<char>>` (`-` free, `X` taken) |
| Code | `displayPassengers()` in the sample-run table format |
| Code | `addPassenger()`: reject out-of-range row, seat letter beyond `seats_per_row`, occupied seat |
| Code | `removePassenger()`: remove by ID, report if ID not found |
| Testing | Tests **Parin's** menu and Passenger code (every menu option, bad inputs) |
| Branch | `feature/flight` |

### Aditya Patel – Airline + second data set
| Area | Tasks |
|---|---|
| Code | `Airline.h` / `Airline.cpp`: `loadData()`, `savePassengerData()`, `displayFlights()`, `findFlight()` |
| Code | Convert `FlightRecord` / `PassengerRecord` into objects and put each passenger on the right flight; build the `vector<PassengerRecord>` for saving |
| Code | Helper to check a passenger ID isn't already used on **any** flight (needed by option 5) |
| Deliverable | `flights_test2.txt` + `passengers_test2.txt` (different values, ≥ 2 flights, ≥ 4 passengers on ≥ 2 flights, no duplicate IDs or seats) |
| Testing | Tests **Agastya's** Flight code (seat map, add/remove edge cases) |
| Branch | `feature/airline` |

---

## Shared by everyone
- **Headers first:** agree on `Flight.h` and `Airline.h` together before writing any `.cpp` code.
- **Report:** each person writes the test cases for the class they tested (input, expected, actual, pass/fail), covering **both** data sets. Parin writes the class design and data flow section; everyone reviews it.
- **Contribution summary:** each person writes their own paragraph.
- **Presentation:** each person presents and answers questions on their own class.
- **Final ZIP:** all `.h`/`.cpp`, 4 data files, `README.txt`. No `.exe`, `a.out`, or `.o` files.

---

## Timeline
| By | Milestone |
|---|---|
| Thu Nov 20 | `Flight.h` + `Airline.h` agreed and merged into `main` |
| Mon Nov 24 | Each class compiles and works on its own; test data files merged |
| Tue Nov 25 | Integration session (all 3): full program runs end to end |
| Thu Nov 27 | All tests run on both data sets; `README.txt` tested on Windows + macOS |
| Fri Nov 28 | Report, contribution summary, ZIP done → **submit** (1 day buffer) |
| Sat Nov 29 | Deadline |

---

## Git rules
1. Always `git pull` on `main` before starting a new branch.
2. One branch per feature (`feature/...`); never commit straight to `main`.
3. Open a pull request and ask one teammate to review. If nobody responds in 24 hours, merge it yourself.
4. Never commit compiled files or the handout PDF (`.gitignore` covers these).
5. Don't edit `FileRecordIO.h` / `.cpp`; they are instructor-supplied.
6. Don't commit a `passengers.txt` changed by option 7 (Save). Restore it with `git checkout passengers.txt`.
