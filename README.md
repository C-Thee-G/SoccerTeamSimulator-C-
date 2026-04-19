# ⚽ Soccer Team Strategy Simulator - README

## 📋 Project Information

| **Field** | **Details** |
|-----------|-------------|
| **Project Name** | Soccer Team Strategy Simulator |
| **Course** | APM11A1 - Advanced Programming |
| **Assessment** | Code Challenge 1 (CC1) |
| **Submission Date** | 2026 |
| **IDE Used** | Microsoft Visual Studio 2022 🖥️ |
| **Language** | C++11 |

---

## 👥 Team Members - Group F (7 Members)

| 🆔 Student Number | 👤 Name | 🎯 Role |
|------------------|--------|---------|
| 221152725 | Mongiwethu Eddy Ncube | Project Manager |
| 220115085 | Sandile Sibeko | 📐 UML Design / Documentation |
| 220068905 | Keamogetse Selebano | 📊 Algorithm Implementation |
| 220122253 | Ndzulamo Michelle Yingwani | 🎨 Strategy Pattern & Testing |
| 220080694 | Hlonipho Nersely Bila | ⚠️ Exception Handling & OOP |
| 220061777 | Zizile Ezona Mbanqi | 🧪 Testing & Sample Outputs |
| 219027546 | Bongane Sithole | 🔍 Sorting & Search Algorithms |

---

## 🚀 How to Open in Visual Studio 2022

1. 🖱️ Open **Visual Studio 2022**
2. 📂 Click **File** → **Open** → **Project/Solution**
3. 🔍 Navigate to `221152725_NCUBE_CC1/SoccerTeamStrategySimulator.sln`
4. ✅ Click **Open**
5. 🏃 Press **Ctrl + F5** to run without debugging
6. 🐛 Press **F5** to run with debugging

---

## 💻 How to Compile (Command Line - Alternative)

### 🔷 Using Visual Studio Developer Command Prompt:

```bash
cl /EHsc /std:c++11 main.cpp Player.cpp Team.cpp FormationStrategy.cpp
main.exe
```

### 🔷 Using g++ (if available):

```bash
g++ -std=c++11 main.cpp Player.cpp Team.cpp FormationStrategy.cpp -o soccer_simulator
soccer_simulator.exe
```

---

## ✅ Features Implemented

### 📐 Part A: Design
- [x] 📊 Complete UML Class Diagram
- [x] 🎯 Singleton Pattern (Team Manager)
- [x] 🔄 Strategy Pattern (Formation Strategy)
- [x] 📋 Clear program flow design

### 💻 Part B: Implementation 
- [x] 🧬 Abstract base class (Player)
- [x] 🧬 Derived classes (GK, DF, MF, ST)
- [x] 🎭 Polymorphism (display() method)
- [x] ➕ Operator overloading (>, <, ==, <<)
- [x] 📦 Templates (PlayerRepository)
- [x] ⚠️ Exception handling (try-catch blocks)

### 🔍 Part B: Algorithms
- [x] 🔎 Linear Search (O(n))
- [x] 🔎 Binary Search (O(log n))
- [x] 📊 Bubble Sort (O(n²))
- [x] ⚡ Quick Sort (O(n log n))

### 🎨 Part B: 
- [x] 🔄 Strategy Pattern (4-4-2, 4-3-3, 3-5-2)

### ⚠️ Part B:
- [x] 🔧 Try-catch blocks throughout
- [x] 💬 Custom error messages

### 📈 Part C: Analysis 
- [x] 📊 Big-O complexity analysis
- [x] ⏱️ Time efficiency comments
- [x] 💾 Space efficiency comments

### 🧪 Part D: Testing 
- [x] 👤 Add players test
- [x] 📋 Display roster test
- [x] ⚙️ Apply strategies test
- [x] 🏆 Match simulation test
- [x] ❌ Error handling test

### 📝 Part E: Documentation 
- [x] 📐 UML diagrams
- [x] 💬 Inline code comments
- [x] 📄 Reflection essay (1/2 page)
- [x] 📸 Sample outputs

---

## 🎮 How to Run the Program

1. 🚀 **Launch the program** in Visual Studio 2022 (**Ctrl+F5**)
2. ✍️ **Enter your team name** when prompted

3. 📋 **Main Menu Options:**

```
=============================================
     SOCCER TEAM STRATEGY SIMULATOR v1.0     
=============================================
Enter your team name: 

========== MAIN MENU ==========
1. ➕ Add Player
2. 📋 Display Team Roster
3. ⚙️ Select Formation Strategy
4. 🔄 Apply Current Strategy
5. 🔍 Search for Player
6. 📊 Sort Players
7. 🏆 Simulate Match
8. 🚪 Exit
================================
```

4. 🔄 **Sample Workflow:**
   - ➕ Add 11 players (various positions)
   - ⚙️ Select a formation (4-4-2, 4-3-3, or 3-5-2)
   - 📋 Display team roster
   - 🏆 Simulate a match
   - 🔍 Search for specific players
   - 📊 Sort players by skill or number

---

## ✅ Input Validation Rules

| 🔍 Field | ✔️ Valid Range | ❌ Error Message |
|----------|----------------|------------------|
| 👤 Player Name | Non-empty | "Player name cannot be empty" |
| 🔢 Jersey Number | 1-99 | "Jersey number must be between 1 and 99" |
| ⭐ Skill Rating | 1-100 | "Skill rating must be between 1 and 100" |
| 👥 Team Size | 0-11 | "Cannot add more than 11 players" |
| 🔄 Duplicate Number | Unique | "Player with jersey number X already exists" |

---

## 🎨 Color Coding (Console Output)

| 🎨 Color | 📌 Usage |
|----------|----------|
| 🔴 Red | Error messages |
| 🟢 Green | Success messages, strategy application |
| 🟡 Yellow | Menu options, strikers |
| 🔵 Blue | Defenders |
| 🔷 Cyan | Midfielders, information |
| 🟣 Magenta | Headers, borders |
| ⚪ White | Default text |

> **💡 Note:** Colors work in Visual Studio 2022 console by default

---

## 📊 Complexity Analysis Summary

| 🔍 Algorithm | ⏱️ Time Complexity | 💾 Space Complexity | 
|--------------|-------------------|---------------------|
| 🔎 Linear Search | O(n) | O(1) |
| 🔎 Binary Search | O(log n) | O(1) |
| 🫧 Bubble Sort | O(n²) | O(1) | 
| ⚡ Quick Sort | O(n log n) | O(log n) |

> **💡 Note:** n ≤ 11 (maximum team size), so all operations complete in negligible time ⚡

---

## 🏗️ Design Patterns Used

### 1. 🎯 Singleton Pattern - Team Class
- **Purpose:** Ensure only one team instance exists
- **Implementation:** Private constructor, static getInstance() method
- **Location:** `Team.h` and `Team.cpp`

### 2. 🔄 Strategy Pattern - FormationStrategy
- **Purpose:** Allow dynamic switching of formations
- **Implementation:** Abstract interface with concrete strategies
- **Concrete Strategies:** FourFourTwo, FourThreeThree, ThreeFiveTwo
- **Location:** `FormationStrategy.h` and `FormationStrategy.cpp`

---

## 🛠️ Visual Studio 2022 Setup Instructions

### 📋 Prerequisites:
- ✅ Visual Studio 2022 (Community, Professional, or Enterprise)
- ✅ Desktop development with C++ workload installed

### 📝 Steps to create the project from scratch:

1. 🖱️ Open **Visual Studio 2022**
2. ➕ Click **Create a new project**
3. 🖥️ Select **Console App (C++)**
4. 📛 Name the project: `SoccerTeamStrategySimulator`
5. ✅ Click **Create**
6. 📄 Add all .h and .cpp files to the project
7. 🔨 Build → **Build Solution** (Ctrl+Shift+B)
8. ▶️ Debug → **Start Without Debugging** (Ctrl+F5)

---

## ❌ Error Handling Examples 

### 🚫 Attempting to add 12th player:
```
[ERROR] Cannot add more than 11 players. Team is full!
```

### 🔄 Duplicate jersey number:
```
[ERROR] Player with jersey number 10 already exists!
```

### ⭐ Invalid skill rating:
```
[ERROR] Skill rating must be between 1 and 100
```

### 👥 Simulating without full team:
```
[ERROR] Cannot simulate match: Team has only 5 players. Need 11 players for a full match!
```

### ⚙️ No formation selected:
```
[ERROR] No formation strategy selected! Please set a strategy first.
```

---

## 🔧 Troubleshooting

| ⚠️ Issue | ✅ Solution |
|----------|-------------|
| 🎨 Colors not showing in console | Colors work by default in VS2022 console |
| 🔨 Compilation errors | Ensure C++11 standard is set (Project Properties → C++ Language Standard → C++11) |
| 🔗 Linker errors | Make sure all .cpp files are added to the project |
| ⌨️ Input buffer issues | `clearInput()` function handles all cases |

---

## ✅ Submission Checklist

- [ ] 📄 Source code (.h and .cpp files)
- [ ] 🗃️ Visual Studio Solution (.sln and .vcxproj files)
- [ ] 📐 UML diagram (PDF)
- [ ] 📊 Complexity analysis (PDF)
- [ ] 📝 Sample outputs (TXT or PDF)
- [ ] 📄 Reflection essay (PDF)
- [ ] 📖 README.md file
- [ ] 🗜️ Compressed as .zip or .rar

---

## 📜 Declaration

We, the undersigned, declare that this project is our original work. All group members have contributed equally to the design, implementation, testing, and documentation of the Soccer Team Strategy Simulator.

### ✍️ Group F Signatures:

| # | 🆔 Student Number | 👤 Name | ✍️ Signature | 📅 Date |
|---|------------------|--------|--------------|---------|
| 1 | 221152725 | Mongiwethu Eddy Ncube |MN | 2026-04-18 |
| 2 | 220115085 | Sandile Sibeko |SB | 2026-04-18 |
| 3 | 220068905 | Keamogetse Selebano | KS | 2026-04-18 |
| 4 | 220122253 | Ndzulamo Michelle Yingwani | NMY | 2026-04-18 |
| 5 | 220080694 | Hlonipho Nersely Bila | HNB | 2026-04-18 |
| 6 | 220061777 | Zizile Ezona Mbanqi | ZEM| 2026-04-18 |
| 7 | 219027546 | Bongane Sithole | BS | 2026-04-18 |

---

## 📞 Contact
- 📚 Course: APM11A1 - Advanced Programming
- 🏫 Institution: University of Johannesburg
- 🖥️ IDE: Visual Studio 2022

---

## 🏁 **END OF README** 🏁


