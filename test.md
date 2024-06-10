# ch1

1. **計算機抽象與技術（Computer Abstractions and Technology）**
   - 計算機架構與組織（Computer Architecture & Organization）
   - 指令集架構（Instruction Set Architecture, ISA）
   - 機器組織（Machine Organization）
   - I/O系統（I/O System）
   - 處理器（Processor）
   - 編譯器（Compiler）
   - 操作系統（Operating System）
   - 應用程序（Application）

2. **五大經典計算機組件（Five Classic Components of a Computer）**
   - 處理器（Processor）
   - 控制（Control）
   - 數據路徑（Datapath）
   - 記憶體（Memory）
   - 輸入/輸出裝置（Input/Output Devices）

3. **計算機革命（The Computer Revolution）**
   - 計算機技術的進步（Progress in Computer Technology）
   - 新應用的可行性（Feasibility of Novel Applications）
   - 計算機無處不在（Computers are Pervasive）

4. **計算機的類型（Classes of Computers）**
   - 個人計算機（Personal Computers）
   - 伺服器計算機（Server Computers）
   - 超級計算機（Supercomputers）
   - 嵌入式計算機（Embedded Computers）

5. **後PC時代（The Post PC Era）**
   - 個人移動設備（Personal Mobile Device, PMD）
   - 雲計算（Cloud Computing）
   - 軟體即服務（Software as a Service, SaaS）

6. **性能理解（Understanding Performance）**
   - 算法（Algorithm）
   - 程序語言、編譯器、架構（Programming Language, Compiler, Architecture）
   - 處理器和記憶體系統（Processor and Memory System）
   - I/O系統（I/O System）

7. **八大計算機架構理念（Eight Great Ideas in Computer Architecture）**
   - 抽象設計（Design for Abstraction）
   - 快速常見案例（Make the Common Case Fast）
   - 通過並行性提高性能（Performance via Parallelism）
   - 通過流水線提高性能（Performance via Pipelining）
   - 通過預測提高性能（Performance via Prediction）
   - 記憶體層次結構（Hierarchy of Memories）
   - 通過冗餘提高可靠性（Dependability via Redundancy）

8. **程序代碼層次（Levels of Program Code）**
   - 高級語言（High-Level Language）
   - 彙編語言（Assembly Language）
   - 機器語言（Machine Language）
   - 控制信號規範（Control Signal Specification）

9. **性能定義（Defining Performance）**
   - 響應時間（Response Time）
   - 吞吐量（Throughput）
   - 相對性能（Relative Performance）

10. **CPU時鐘（CPU Clocking）**
    - 時鐘週期（Clock Cycle Time）
    - 時鐘頻率（Clock Frequency）

11. **指令計數和CPI（Instruction Count and CPI）**
    - 指令計數（Instruction Count, IC）
    - 平均每指令週期數（Cycles Per Instruction, CPI）

12. **功率趨勢（Power Trends）**
    - 功率牆（The Power Wall）

13. **多處理器（Multiprocessors）**
    - 多核微處理器（Multicore Microprocessors）
    - 並行編程（Parallel Programming）

14. **SPEC CPU基準測試（SPEC CPU Benchmark）**
    - 程序執行時間（Elapsed Time to Execute a Selection of Programs）
    - 標準性能評估公司（Standard Performance Evaluation Corporation, SPEC）

15. **Amdahl定律（Amdahl's Law）**
    - 增強的加速比（Speedup due to Enhancement）

# ch2

1. **計算機抽象與技術（Computer Abstractions and Technology）**
   - **計算機架構與組織（Computer Architecture & Organization）**：計算機架構指的是計算機系統的設計和功能，組織則是指實現這些功能的具體方式。
   - **指令集架構（Instruction Set Architecture, ISA）**：ISA是一組指令，定義了處理器可以執行的操作。
   - **機器組織（Machine Organization）**：包括處理器、記憶體和I/O設備的內部結構和相互連接。
   - **I/O系統（I/O System）**：負責處理器與外部設備之間的數據交換。
   - **處理器（Processor）**：執行指令和處理數據的核心部件。
   - **編譯器（Compiler）**：將高級語言轉換為機器代碼的工具。
   - **操作系統（Operating System）**：管理硬體資源和提供基礎服務的軟體。
   - **應用程序（Application）**：用戶使用的軟體，執行特定任務。

2. **五大經典計算機組件（Five Classic Components of a Computer）**
   - **處理器（Processor）**：包括控制單元和數據路徑，負責執行指令。
   - **控制（Control）**：管理指令的解碼和執行。
   - **數據路徑（Datapath）**：處理和傳輸數據的電路。
   - **記憶體（Memory）**：存儲指令和數據。
   - **輸入/輸出裝置（Input/Output Devices）**：與外部世界進行數據交換的設備。

3. **計算機革命（The Computer Revolution）**
   - **計算機技術的進步（Progress in Computer Technology）**：指的是硬體和軟體技術的快速發展。
   - **新應用的可行性（Feasibility of Novel Applications）**：新的計算能力使得以前不可行的應用成為可能。
   - **計算機無處不在（Computers are Pervasive）**：計算機技術已經滲透到生活的各個方面。

4. **計算機的類型（Classes of Computers）**
   - **個人計算機（Personal Computers）**：供個人使用的計算機。
   - **伺服器計算機（Server Computers）**：提供服務的計算機，如網頁伺服器。
   - **超級計算機（Supercomputers）**：執行高性能計算的計算機。
   - **嵌入式計算機（Embedded Computers）**：嵌入到其他設備中的計算機，如手機。

5. **後PC時代（The Post PC Era）**
   - **個人移動設備（Personal Mobile Device, PMD）**：如智能手機和平板電腦。
   - **雲計算（Cloud Computing）**：通過互聯網提供計算資源和服務。
   - **軟體即服務（Software as a Service, SaaS）**：通過互聯網提供軟體應用。

6. **性能理解（Understanding Performance）**
   - **算法（Algorithm）**：解決問題的步驟和方法。
   - **程序語言、編譯器、架構（Programming Language, Compiler, Architecture）**：影響程序效率的因素。
   - **處理器和記憶體系統（Processor and Memory System）**：影響計算速度的硬體組件。
   - **I/O系統（I/O System）**：影響數據傳輸速度的設備。

7. **八大計算機架構理念（Eight Great Ideas in Computer Architecture）**
   - **抽象設計（Design for Abstraction）**：通過抽象簡化設計。
   - **快速常見案例（Make the Common Case Fast）**：優化常見操作。
   - **通過並行性提高性能（Performance via Parallelism）**：同時執行多個操作。
   - **通過流水線提高性能（Performance via Pipelining）**：分段執行操作。
   - **通過預測提高性能（Performance via Prediction）**：預測未來操作以提高效率。
   - **記憶體層次結構（Hierarchy of Memories）**：使用不同速度和容量的記憶體。
   - **通過冗餘提高可靠性（Dependability via Redundancy）**：增加冗餘以提高可靠性。

8. **程序代碼層次（Levels of Program Code）**
   - **高級語言（High-Level Language）**：如C++、Java。
   - **彙編語言（Assembly Language）**：低級語言，與機器碼一一對應。
   - **機器語言（Machine Language）**：處理器直接執行的二進制代碼。
   - **控制信號規範（Control Signal Specification）**：控制硬體操作的信號。

9. **性能定義（Defining Performance）**
   - **響應時間（Response Time）**：完成單個任務所需的時間。
   - **吞吐量（Throughput）**：單位時間內完成的任務數量。
   - **相對性能（Relative Performance）**：與基準系統相比的性能。

10. **CPU時鐘（CPU Clocking）**
    - **時鐘週期（Clock Cycle Time）**：時鐘信號的周期。
    - **時鐘頻率（Clock Frequency）**：每秒的時鐘週期數。

11. **指令計數和CPI（Instruction Count and CPI）**
    - **指令計數（Instruction Count, IC）**：程序執行的指令數量。
    - **平均每指令週期數（Cycles Per Instruction, CPI）**：執行每條指令所需的平均周期數。

12. **功率趨勢（Power Trends）**
    - **功率牆（The Power Wall）**：功率消耗限制了性能的提高。

13. **多處理器（Multiprocessors）**
    - **多核微處理器（Multicore Microprocessors）**：包含多個處理核心的處理器。
    - **並行編程（Parallel Programming）**：同時執行多個計算任務的編程方法。

14. **SPEC CPU基準測試（SPEC CPU Benchmark）**
    - **程序執行時間（Elapsed Time to Execute a Selection of Programs）**：執行選定程序所需的時間。
    - **標準性能評估公司（Standard Performance Evaluation Corporation, SPEC）**：提供基準測試的組織。

15. **Amdahl定律（Amdahl's Law）**
    - **增強的加速比（Speedup due to Enhancement）**：性能增強的理論最大加速比。

# ch3

1. **算術運算（Arithmetic for Computers）**
   - 整數運算（Operations on integers）
     - 加法和減法（Addition and Subtraction）
     - 乘法和除法（Multiplication and Division）
     - 處理溢位（Dealing with overflow）

2. **浮點數（Floating Point）**
   - 浮點數表示法（Representation for non-integral numbers）
   - IEEE 754浮點數標準（IEEE 754 floating point standard）
     - 單精度（Single precision）
     - 雙精度（Double precision）

3. **整數表示法（Integer Representation）**
   - 二進制數（Binary number）
   - 兩補數（Two's complement）
   - 符號-幅值（Sign Magnitude）

4. **溢位檢測（Overflow Detection）**
   - 溢位的處理（Dealing with Overflow）
   - 溢位檢測邏輯（Overflow Detection Logic）

5. **乘法和除法（Multiplication and Division）**
   - 乘法硬體（Multiplication Hardware）
   - 除法硬體（Division Hardware）
   - MIPS乘法和除法指令（MIPS Multiplication and Division Instructions）

6. **多媒體算術（Arithmetic for Multimedia）**
   - SIMD（單指令多數據，Single Instruction, Multiple Data）
   - 飽和運算（Saturating operations）

7. **布林代數與邏輯閘（Boolean Algebra & Gates）**
   - 多工器（Multiplexor）
   - 算術邏輯單元（ALU, Arithmetic Logic Unit）

8. **浮點數例子（Floating Point Example）**
   - 特殊情況（Special cases）
     - 無窮大（Infinity）
     - 非數（NaN, Not a Number）

9. **結論（Concluding Remarks）**
   - 位元沒有固有意義（Bits have no inherent meaning）
   - 數字的計算機表示（Computer representations of numbers）
   - MIPS指令集架構（MIPS ISA, Instruction Set Architecture）

# ch4

1. **MIPS架構簡介（Introduction to MIPS Architecture）**
   - 簡化的MIPS實現（Simplified MIPS Implementation）
   - 記憶體參考指令（Memory-reference instructions）：`lw`、`sw`
   - 算術邏輯指令（Arithmetic-logic instructions）：`add`、`sub`、`and`、`or`、`slt`
   - 控制流指令（Control flow instructions）：`beq`、`j`

2. **通用實現（Generic Implementation）**
   - 使用程式計數器（Program Counter, PC）供應指令地址並從記憶體中取指令（Fetch instructions from memory）
   - 解碼指令並讀取寄存器（Decode instructions and read registers）
   - 執行指令（Execute instructions）

3. **時鐘方法（Clocking Methodologies）**
   - 邊緣觸發方法（Edge-triggered methodology）
   - 典型執行（Typical execution）
     - 讀取狀態元素的內容（Read contents of state elements）
     - 通過組合邏輯傳遞值（Send values through combinational logic）
     - 將結果寫入一個或多個狀態元素（Write results to one or more state elements）

4. **取指令（Fetching Instructions）**
   - 從指令記憶體中讀取指令（Reading the instruction from the Instruction Memory）
   - 更新PC以保存下一條指令的地址（Updating the PC to hold the address of the next instruction）

5. **解碼指令（Decoding Instructions）**
   - 將指令的位元發送到控制單元（Sending bits to the Control Unit）
   - 從寄存器文件中讀取兩個值（Reading two values from the Register File）

6. **執行R格式操作（Executing R Format Operations）**
   - 執行操作並將結果存回寄存器文件（Perform the operation and store the result back into the Register File）

7. **執行加載和存儲操作（Executing Load and Store Operations）**
   - 計算記憶體地址（Compute memory address）
   - 將值寫入數據記憶體（Write value to Data Memory）
   - 從數據記憶體讀取值並寫入寄存器文件（Read value from Data Memory and write to Register File）

8. **執行分支操作（Executing Branch Operations）**
   - 比較操作數並計算分支目標地址（Compare operands and compute branch target address）

9. **執行跳轉操作（Executing Jump Operations）**
   - 替換PC的低28位（Replace lower 28 bits of the PC）

10. **創建單一數據路徑（Creating a Single Datapath）**
    - 組裝數據路徑段並添加控制線和多工器（Assemble the datapath segments and add control lines and multiplexors）

11. **多週期數據路徑方法（Multicycle Datapath Approach）**
    - 將指令分解為多個步驟，每個步驟需要一個時鐘週期（Break up instructions into steps, each taking a cycle）
    - 在不同的時鐘週期內使用功能單元（Use functional units more than once per instruction）

12. **多週期控制單元（Multicycle Control Unit）**
    - 使用有限狀態機（FSM）進行控制（Use a finite state machine for control）

13. **加載指令的五個步驟（Five Steps of the Load Instruction）**
    - 指令取指（Instruction Fetch）
    - 指令解碼（Instruction Decode）
    - 執行（Execute）
    - 記憶體讀取（Memory Read）
    - 寫回（Write Back）

14. **單週期與多週期的優缺點（Single Cycle vs. Multicycle Advantages & Disadvantages）**
    - 單週期設計的簡單性（Simplicity of single cycle design）
    - 多週期設計的時鐘效率（Clock efficiency of multicycle design）

# ch5

1. **MIPS架構進階（More on MIPS Architecture）**
   - 單週期數據路徑設計回顧（Review of Single Cycle Datapath Design）
   - 幾乎完整的單週期數據路徑（Almost Complete Single Cycle Datapath）
   - ALU控制（ALU Control）

2. **ALU控制邏輯（ALU Control Logic）**
   - ALU操作基於指令類型和功能碼（ALU's operation based on instruction type and function code）
   - ALU控制真值表（ALU Control Truth Table）

3. **多週期數據路徑（Multicycle Datapath）**
   - 多週期數據路徑方法（Multicycle Datapath Approach）
   - 多週期控制單元（Multicycle Control Unit）

4. **加載指令的五個步驟（Five Steps of the Load Instruction）**
   - 指令取指（Instruction Fetch）
   - 指令解碼（Instruction Decode）
   - 執行（Execute）
   - 記憶體讀取（Memory Read）
   - 寫回（Write Back）

5. **指令取指（Instruction Fetch）**
   - 使用PC從記憶體中獲取指令並將其放入指令寄存器（Use PC to get instruction from memory and put it in the Instruction Register）
   - 將PC增加4並將結果放回PC中（Increment the PC by 4 and put the result back in the PC）

6. **指令解碼（Instruction Decode）**
   - 讀取寄存器rs和rt的值（Read registers rs and rt in case we need them）
   - 計算分支地址（Compute the branch address in case the instruction is a branch）

7. **指令執行（Instruction Execution）**
   - R型指令執行（R-type Instruction Execution）
   - 記憶體讀寫地址計算（Memory Read/Write Address Computation）
   - 分支完成或跳轉完成（Branch Completion or Jump Completion）

8. **記憶體訪問（Memory Access）**
   - 記憶體讀取（Memory Read Access）
   - 記憶體寫入完成（Memory Write Completion）
   - R型指令完成（R-type Instruction Completion）

9. **寫回（Write Back）**
   - 將剛從記憶體讀取的數據寫回寄存器文件（Write back into the register file the data just read from memory for lw instruction）

10. **多週期控制（Multicycle Control）**
    - 使用有限狀態機進行控制（Use a finite state machine for control）
    - 狀態寄存器（State Register）
    - 下一狀態函數（Next State Function）
    - 輸出函數（Output Function）

11. **微程序設計（Microprogramming Design）**
    - 微程序指令（Microinstruction）
    - 微程序計數器（Microprogram Counter）
    - 控制PLA（Control PLA）

12. **多週期優缺點（Multicycle Advantages & Disadvantages）**
    - 使用時鐘周期效率高（Uses the clock cycle efficiently）
    - 多週期實現允許更快的時鐘速度（Multicycle implementations allow faster clock rates）
    - 需要額外的內部狀態寄存器、多工器和更複雜的控制（Requires additional internal state registers, muxes, and more complicated control）

13. **單週期與多週期的定時（Single Cycle vs. Multiple Cycle Timing）**
    - 單週期實現（Single Cycle Implementation）
    - 多週期實現（Multiple Cycle Implementation）

# ch6

1. **基本MIPS流水線（Basic MIPS Pipelining）**
   - 如何使其更快（How Can We Make It Even Faster）
     - 將多指令週期分割為更小的步驟（Split the multiple instruction cycle into smaller steps）
     - 在當前指令完成之前開始取指和執行下一條指令（Start fetching and executing the next instruction before the current one has completed）

2. **流水線的靈感：汽車裝配線（Inspiration: Automobile Assembly Line）**
   - 流水線：其自然性（Pipelining: Its Natural）
     - 洗衣示例（Laundry Example）

3. **流水線MIPS處理器（A Pipelined MIPS Processor）**
   - 提高吞吐量（Improves throughput）
     - 總工作量在一定時間內完成（Total amount of work done in a given time）
   - 指令延遲（Instruction latency）
     - 執行時間、延遲時間、響應時間（Execution time, delay time, response time）

4. **單週期、多週期與流水線（Single Cycle, Multiple Cycle, vs. Pipeline）**
   - 單週期實現（Single Cycle Implementation）
   - 多週期實現（Multiple Cycle Implementation）
   - 流水線實現（Pipeline Implementation）

5. **MIPS流水線數據路徑修改（MIPS Pipeline Datapath Modifications）**
   - 在每個流水線階段之間添加狀態寄存器以隔離它們（Add state registers between each pipeline stage to isolate them）

6. **流水線MIPS ISA（Pipelining the MIPS ISA）**
   - 使其變得容易的因素（What makes it easy）
     - 所有指令都是相同長度（All instructions are the same length）
     - 僅有少數指令格式（Few instruction formats）

7. **流水線危險（Pipeline Hazards）**
   - 結構性危險（Structural hazards）
     - 兩條不同指令在同一時間嘗試使用相同資源（Attempt to use the same resource by two different instructions at the same time）
   - 數據危險（Data hazards）
     - 嘗試在數據準備好之前使用它（Attempt to use data before it is ready）
   - 控制危險（Control hazards）
     - 嘗試在條件被評估並計算出新的PC目標地址之前做出程序控制流的決定（Attempt to make a decision about program control flow before the condition has been evaluated and the new PC target address calculated）

8. **解決流水線危險的方法（Resolving Pipeline Hazards）**
   - 等待（Waiting）
   - 前推（Forwarding）
   - 停止（Stalling）

9. **分支指令引起的控制危險（Branch Instructions Cause Control Hazards）**
   - 修正數據路徑以保存寄存器寫地址（Corrected Datapath to Save RegWrite Addr）

10. **其他可能的流水線結構（Other Pipeline Structures Are Possible）**
    - 乘法操作（Multiply operation）
    - 數據記憶體訪問速度較慢（Data memory access is slower）

11. **流水線的總結（Summary of Pipelining）**
    - 所有現代處理器都使用流水線技術（All modern processors use pipelining）
    - 單個任務的延遲（Latency of single task）
    - 整個工作負載的吞吐量（Throughput of entire workload）
    - 潛在速度提升（Potential speedup）
    - 必須檢測並解決危險（Must detect and resolve hazards）

# ch7

1. **主要記憶體（Main Memory）**
   - 記憶體性能差距（Memory Performance Gap）
     - 處理器性能增長（Processor Performance Growth）：55%/年（2倍/1.5年）
     - DRAM性能增長（DRAM Performance Growth）：7%/年（2倍/10年）
     - 處理器與記憶體性能差距（Processor-Memory Performance Gap）：每年增長50%

2. **記憶體層次結構目標（Memory Hierarchy Goal）**
   - 大型記憶體速度慢而快速記憶體較小（Large memories are slow and fast memories are small）
   - 如何創建一個看似大、便宜且快速的記憶體（How to create a memory that appears large, cheap, and fast most of the time）
     - 使用層次結構（With hierarchy）
     - 使用並行性（With parallelism）

3. **典型記憶體層次結構（A Typical Memory Hierarchy）**
   - 控制（Control）
   - 數據路徑（Datapath）
   - 二級緩存（Second Level Cache, SRAM）
   - 主記憶體（Main Memory, DRAM）
   - 次級記憶體（Secondary Memory, Disk）

4. **記憶體層次結構特徵（Characteristics of the Memory Hierarchy）**
   - 從處理器到記憶體的距離增加（Increasing distance from the processor in access time）
   - 每個層次的記憶體大小（Size of the memory at each level）
   - 包含性（Inclusivity）：L1緩存中的內容是L2緩存內容的子集，L2緩存中的內容是主記憶體內容的子集，主記憶體中的內容是次級記憶體內容的子集

5. **記憶體層次結構技術（Memory Hierarchy Technologies）**
   - 緩存使用SRAM（Caches use SRAM）
     - 低密度（6個晶體管單元）、高功耗、昂貴、快速（Low density, high power, expensive, fast）
     - 靜態：內容將持續（Static: content will last）
   - 主記憶體使用DRAM（Main Memory uses DRAM）
     - 高密度（1個晶體管單元）、低功耗、便宜、慢（High density, low power, cheap, slow）

6. **記憶體性能指標（Memory Performance Metrics）**
   - 延遲（Latency）：訪問一個字的時間（Time to access one word）
   - 訪問時間（Access time）：從請求到數據可用（或寫入）的時間（Time between request and when the data is available (or written)）
   - 週期時間（Cycle time）：兩次請求之間的時間（Time between requests）
   - 帶寬（Bandwidth）：每單位時間內從記憶體提供給處理器的數據量（How much data from the memory can be supplied to the processor per unit time）

7. **經典RAM組織（Classical RAM Organization）**
   - 行解碼器（Row Decoder）
   - 列選擇器與I/O電路（Column Selector & I/O Circuits）

8. **經典DRAM操作（Classical DRAM Operation）**
   - DRAM組織（DRAM Organization）
     - N行xN列xM位（N rows x N columns x M-bit）
     - 每次訪問M位（Read or Write M-bit at a time）
     - 每次M位訪問需要一個RAS/CAS週期（Each M-bit access requires a RAS/CAS cycle）

9. **頁模式DRAM操作（Page Mode DRAM Operation）**
   - 頁模式DRAM（Page Mode DRAM）
     - 讀取行後只需要CAS訪問其他M位字（After a row is read into the SRAM register, only CAS is needed to access other M-bit words on that row）

10. **同步DRAM（Synchronous DRAM, SDRAM）操作**
    - 同步DRAM操作（Synchronous DRAM Operation）
      - 讀取行後與地址一起傳輸一個數據突發（After a row is read into the SRAM register, transfer a burst of data from a series of sequential addresses within that row）

11. **其他DRAM架構（Other DRAM Architectures）**
    - 雙倍數據速率SDRAM（Double Data Rate SDRAM, DDR-SDRAM）
      - 在時鐘的上升和下降邊緣傳輸數據（Transfer data on both the rising and falling edge of the clock）

12. **記憶體系統概要（DRAM Memory System Summary）**
    - 匹配緩存特性（Match the cache characteristics）
      - 使用支持快速多字訪問的DRAM（Use DRAMs that support fast multiple word accesses, preferably ones that match the block size of the cache）

# ch8

1. **記憶體層次結構回顧（Review: The Memory Hierarchy）**
   - 記憶體層次結構的目標（Memory Hierarchy Goal）
     - 利用局部性原則（Take advantage of the principle of locality）
     - 提供用戶看似大、便宜且快速的記憶體（Present the user with as much memory as is available in the cheapest technology at the speed offered by the fastest technology）

2. **記憶體層次結構為何有效（The Memory Hierarchy: Why Does it Work?）**
   - 時間局部性（Temporal Locality）
     - 保持最近訪問的數據靠近處理器（Keep most recently accessed data items closer to the processor）
   - 空間局部性（Spatial Locality）
     - 將包含連續字的塊移動到上層（Move blocks consisting of contiguous words to the upper levels）

3. **記憶體層次結構術語（The Memory Hierarchy: Terminology）**
   - 命中（Hit）：數據在上層的某個塊中（Data is in some block in the upper level）
   - 命中率（Hit Rate）：在上層找到的記憶體訪問的比例（The fraction of memory accesses found in the upper level）
   - 命中時間（Hit Time）：訪問上層的時間（Time to access the upper level）
   - 未命中（Miss）：數據不在上層，需要從下層檢索（Data is not in the upper level and needs to be retrieved from a block in the lower level）
   - 未命中率（Miss Rate）：未命中的比例（The fraction of memory accesses not found in the upper level）
   - 未命中懲罰（Miss Penalty）：替換上層塊和將塊傳遞給處理器的時間（Time to replace a block in the upper level and deliver it to the processor）

4. **記憶體層次結構的管理（How is the Hierarchy Managed?）**
   - 寄存器（Registers）：由編譯器管理（Managed by the compiler）
   - 緩存（Cache）：由緩存控制器硬體管理（Managed by the cache controller hardware）
   - 主記憶體（Main Memory）：由操作系統管理（Managed by the operating system）
   - 虛擬記憶體（Virtual Memory）：由操作系統和硬體協助管理（Managed by the operating system with hardware assistance）

5. **直接映射緩存（Direct Mapped Cache）**
   - 每個數據項在緩存中只有一個位置（For each item of data at the lower level, there is exactly one location in the cache where it might be）
   - 地址映射（Address Mapping）：塊地址對緩存塊數取模（Block address modulo the number of blocks in the cache）

6. **處理緩存命中（Handling Cache Hits）**
   - 讀取命中（Read Hits）：這是我們想要的（This is what we want!）
   - 寫入命中（Write Hits）：允許緩存和記憶體不一致（Allow cache and memory to be inconsistent）
     - 僅將數據寫入緩存塊（Write-back）
     - 將數據寫入緩存塊和下一層記憶體（Write-through）

7. **寫緩衝區（Write Buffer）**
   - 寫緩衝區在緩存和主記憶體之間（Write buffer between the cache and main memory）
   - 處理器將數據寫入緩存和寫緩衝區（Processor writes data into the cache and the write buffer）
   - 記憶體控制器將寫緩衝區的內容寫入記憶體（Memory controller writes contents of the write buffer to memory）

8. **緩存未命中的來源（Sources of Cache Misses）**
   - 強制性未命中（Compulsory Misses）：冷啟動或進程遷移（Cold start or process migration, first reference）
   - 衝突未命中（Conflict Misses）：多個記憶體位置映射到相同的緩存位置（Multiple memory locations mapped to the same cache location）
   - 容量未命中（Capacity Misses）：緩存無法包含程序訪問的所有塊（Cache cannot contain all blocks accessed by the program）

9. **多字塊直接映射緩存（Multiword Block Direct Mapped Cache）**
   - 每個塊包含多個字（Each block contains multiple words）
   - 利用空間局部性（Taking advantage of spatial locality）

10. **緩存設計空間（Cache Design Space）**
    - 總大小、塊大小、關聯度（Total size, block size, associativity）
    - 寫入命中策略（Write-hit policy）：寫入穿透（Write-through）、寫回（Write-back）
    - 寫入未命中策略（Write-miss policy）：寫分配（Write-allocate）、寫緩衝區（Write buffers）
