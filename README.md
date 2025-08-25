# Gaussian-Elimination
Gaussian elimination is a systematic algorithm used to solve systems of linear equations by transforming the associated augmented matrix into row echelon form (or reduced row echelon form) through a series of elementary row operations. It’s a fundamental method in linear algebra, named after Carl Friedrich Gauss, and is widely used in mathematics, engineering, and computer science for problems involving linear systems.

### Key Concepts
- **System of Linear Equations**: A set of equations like:
  ```
  a₁x + b₁y + c₁z = d₁
  a₂x + b₂y + c₂z = d₂
  a₃x + b₃y + c₃z = d₃
  ```
  where \(x\), \(y\), and \(z\) are unknowns, and \(a_i\), \(b_i\), \(c_i\), and \(d_i\) are constants.
- **Augmented Matrix**: The system is represented as a matrix combining the coefficients and constants, e.g., for the above system:
  ```
  [ a₁ b₁ c₁ | d₁ ]
  [ a₂ b₂ c₂ | d₂ ]
  [ a₃ b₃ c₃ | d₃ ]
  ```
- **Row Echelon Form (REF)**: A matrix where:
  - All nonzero rows are above any rows of all zeros.
  - The leading coefficient (pivot) of each nonzero row is 1 and is to the right of the pivot in the row above.
  - All entries below each pivot are zero.
- **Elementary Row Operations**:
  1. Swap two rows.
  2. Multiply a row by a nonzero constant.
  3. Add a multiple of one row to another row.

### Steps of Gaussian Elimination
1. **Form the Augmented Matrix**: Write the system of equations as a matrix, including the constants on the right-hand side.
2. **Forward Elimination**:
   - Use row operations to make the matrix upper triangular (or row echelon form).
   - Start with the first column: choose a pivot (nonzero element, ideally the largest to minimize numerical errors), make it 1 by scaling the row, and eliminate all entries below it by subtracting multiples of the pivot row.
   - Move to the next column and repeat until the matrix is in row echelon form.
3. **Back Substitution**:
   - If aiming for reduced row echelon form (RREF), continue row operations to make all pivots 1 and eliminate all entries above pivots.
   - Otherwise, solve the system from bottom to top using the row echelon form, substituting known values to find each variable.

### Example
For the system:
```
a + b + c = 2
a - b + c = 0
a = 0
```
1. **Augmented Matrix**:
   ```
   [ 1  1  1 | 2 ]
   [ 1 -1  1 | 0 ]
   [ 1  0  0 | 0 ]
   ```
2. **Forward Elimination**:
   - Eliminate \(a\) from rows 2 and 3 using row 1:
     - Row 2: Row 2 - Row 1 → `[0 -2 0 | -2]`
     - Row 3: Row 3 - Row 1 → `[0 -1 -1 | -2]`
     - Matrix becomes:
       ```
       [ 1  1  1 |  2 ]
       [ 0 -2  0 | -2 ]
       [ 0 -1 -1 | -2 ]
       ```
   - Eliminate \(b\) from row 3 using row 2:
     - Scale row 2: Row 2 / -2 → `[0 1 0 | 1]`
     - Row 3: Row 3 - (-1) * Row 2 → `[0 0 -1 | -1]`
     - Matrix becomes:
       ```
       [ 1  1  1 |  2 ]
       [ 0  1  0 |  1 ]
       [ 0  0 -1 | -1 ]
       ```
3. **Back Substitution**:
   - From row 3: \(-c = -1 → c = 1\)
   - From row 2: \(b = 1\)
   - From row 1: \(a + b + c = 2 → a + 1 + 1 = 2 → a = 0\)
   - Solution: \([a, b, c] = [0, 1, 1]\)

### Properties and Considerations
- **Efficiency**: Gaussian elimination has a time complexity of \(O(n^3)\) for an \(n \times n\) system, making it efficient for small to medium-sized systems.
- **Pivoting**: To avoid division by zero or numerical instability, partial pivoting (swapping rows to choose the largest pivot) is often used.
- **Applications**: Solving linear systems, finding matrix inverses, computing determinants, and applications in physics, engineering, and computer graphics.
- **Limitations**:
  - Fails if the matrix is singular (no unique solution or no solution).
  - Numerical errors can accumulate for large systems with floating-point arithmetic, requiring techniques like pivoting or iterative methods for better stability.
 
- الحذف الغاوسي هو خوارزمية منهجية تُستخدم لحل أنظمة المعادلات الخطية بتحويل المصفوفة الموسعة المرتبطة بها إلى صيغة صفية (أو صيغة صفية مخفضة) من خلال سلسلة من عمليات الصفوف الأولية. وهي طريقة أساسية في الجبر الخطي، سُميت تيمنًا بكارل فريدريش غاوس، وتُستخدم على نطاق واسع في الرياضيات والهندسة وعلوم الحاسوب لحل المسائل المتعلقة بالأنظمة الخطية. ### المفاهيم الأساسية
- **نظام المعادلات الخطية**: مجموعة معادلات مثل:
```
a₁x + b₁y + c₁z = d₁
a₂x + b₂y + c₂z = d₂
a₃x + b₃y + c₃z = d₃
```
حيث \(x\) و\(y\) و\(z\) مجهولات، و\(a_i\) و\(b_i\) و\(c_i\) و\(d_i\) ثوابت.
- **المصفوفة الموسعة**: يُمثَّل النظام كمصفوفة تجمع المعاملات والثوابت، على سبيل المثال، للنظام المذكور أعلاه:
```
[a₁ b₁ c₁ | d₁ ]
[ a₂ b₂ c₂ | d₂ ]
[ a₃ b₃ c₃ | d₃ ]
```
- **صيغة الصف المتدرج (REF)**: مصفوفة حيث:
- جميع الصفوف غير الصفرية تكون أعلى أي صفوف جميع أصفارها.
- المعامل الرئيسي (نقطة الارتكاز) لكل صف غير صفري هو 1، وهو على يمين نقطة الارتكاز في الصف الذي يسبقه.
- جميع المدخلات أسفل كل نقطة ارتكاز تساوي صفرًا.
- **عمليات الصفوف الأولية**:
1. تبديل صفين.
2. ضرب صف بثابت غير صفري.
3. إضافة مضاعفات صف إلى صف آخر.

### خطوات الحذف الغاوسي
1. **تكوين المصفوفة الموسعة**: اكتب نظام المعادلات كمصفوفة، مع تضمين الثوابت في الطرف الأيمن.
٢. **الحذف الأمامي**:
- استخدم عمليات الصفوف لجعل المصفوفة مثلثة علوية (أو شكل تدرج الصفوف).
- ابدأ بالعمود الأول: اختر عنصرًا محوريًا (عنصرًا غير صفري، ويفضل أن يكون الأكبر لتقليل الأخطاء العددية)، واجعله ١ عن طريق تغيير حجم الصف، واحذف جميع المدخلات التي تقع أسفله بطرح مضاعفات صف المحور.
- انتقل إلى العمود التالي وكرر العملية حتى تصبح المصفوفة في شكل تدرج الصفوف.

٣. **الاستبدال العكسي**:
- إذا كنت ترغب في استخدام شكل تدرج الصفوف المصغر (RREF)، فتابع عمليات الصفوف لجعل جميع العناصر المحورية ١ واحذف جميع المدخلات التي تقع فوقها.
- وإلا، فاحل النظام من الأسفل إلى الأعلى باستخدام شكل تدرج الصفوف، مع استبدال القيم المعروفة لإيجاد كل متغير.

### مثال
للنظام:
```
أ + ب + ج = ٢
أ - ب + ج = ٠
أ = ٠
```
١. **المصفوفة المُوسّعة**:
```
[ ١ ١ ١ | ٢ ]
[ ١ - ١ ١ | ٠ ]
[ ١ ٠ ٠ | ٠ ]
```
٢. **الحذف المباشر**:
- حذف \(أ\) من الصفين ٢ و٣ باستخدام الصف ١:
- الصف ٢: الصف ٢ - الصف ١ → `[٠ - ٢ ٠ | -٢]`
- الصف ٣: الصف ٣ - الصف ١ → `[٠ - ١ - ١ | -٢]`
- تصبح المصفوفة:
```
[ ١ ١ ١ | ٢ ]
[ ٠ - ٢ ٠ | -٢ ]
[ ٠ - ١ - ١ | -٢ ]
```
- احذف \(b\) من الصف ٣ باستخدام الصف ٢:
- عدّل مقياس الصف ٢: الصف ٢ / -٢ → `[٠ ١ ٠ | ١]`
- الصف ٣: الصف ٣ - (-١) * الصف ٢ → `[٠ ٠ -١ | -١]`
- تصبح المصفوفة:
```
[ ١ ١ ١ | ٢ ]
[ ٠ ١ ٠ | ١ ]
[ ٠ ٠ -١ | -١ ]
```
٣. **التعويض العكسي**:
- من الصف ٣: \(-c = -١ → c = ١\)
- من الصف ٢: \(b = ١\)
- من الصف ١: \(a + b + c = ٢ → a + ١ + ١ = ٢ → a = ٠\)
- الحل: \([a, b, c] = [٠, ١, ١]\)

### الخصائص والاعتبارات
- **الكفاءة**: تبلغ تعقيدات الحذف الغاوسي O(n^3)\) لنظام ذي عدد مرات n، مما يجعله فعالاً للأنظمة الصغيرة والمتوسطة.
- **التمحور**: لتجنب القسمة على الصفر أو عدم الاستقرار العددي، يُستخدم التمحور الجزئي (تبديل الصفوف لاختيار أكبر محور).
- **التطبيقات**: حل الأنظمة الخطية، وإيجاد معكوسات المصفوفات، وحساب المحددات، وتطبيقات في الفيزياء والهندسة والرسومات الحاسوبية.
- **القيود**:
- يفشل الحل إذا كانت المصفوفة مفردة (لا يوجد حل وحيد أو لا يوجد حل).
- قد تتراكم الأخطاء العددية في الأنظمة الكبيرة ذات العمليات الحسابية ذات الفاصلة العائمة، مما يتطلب تقنيات مثل التمحور أو الطرق التكرارية لتحسين الاستقرار.

تُعد هذه الطريقة أساسية في الجبر الخطي، وتُطبق في العديد من المكتبات العددية (مثل NumPy وMATLAB). يوضح برنامج C++ الخاص بك هذه العملية من خلال تحليل المعادلات، وتكوين المصفوفة، وتطبيق هذه الخطوات لإيجاد متجه الحل \([0, 1, 1]\) للنظام المعطى.

This method is foundational in linear algebra and is implemented in many numerical libraries (e.g., NumPy, MATLAB). Your C++ program demonstrates this process by parsing equations, forming the matrix, and applying these steps to find the solution vector \([0, 1, 1]\) for the given system.
