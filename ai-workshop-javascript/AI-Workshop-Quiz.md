# AI Workshop Quiz - Questions and Answers

## 📝 Pre-Workshop Assessment (5 minutes)

### Question 1: Basic AI Knowledge

**What is the main difference between traditional programming and machine learning?**

A) Traditional programming is faster
B) Machine learning uses more memory
C) Traditional programming uses explicit rules, machine learning learns patterns from data
D) There is no significant difference

**Answer:** C) Traditional programming uses explicit rules, machine learning learns patterns from data

**Explanation:** Traditional programming involves writing explicit instructions, while machine learning allows computers to learn patterns and make decisions based on data.

---

### Question 2: Types of Machine Learning

**Which type of machine learning would you use to predict house prices?**

A) Classification
B) Regression  
C) Clustering
D) Reinforcement Learning

**Answer:** B) Regression

**Explanation:** Regression is used to predict continuous numerical values like prices, temperatures, or ages.

---

## 📚 Mid-Workshop Knowledge Check (10 minutes)

### Question 3: K-Nearest Neighbors

**How does the K-Nearest Neighbors algorithm make predictions?**

A) It creates a set of rules
B) It finds the most similar examples and uses their labels
C) It calculates mathematical formulas
D) It uses random selection

**Answer:** B) It finds the most similar examples and uses their labels

**Explanation:** KNN works by finding the k most similar training examples and using their labels to make a prediction.

---

### Question 4: Decision Trees

**In our iris flower classifier, which feature does the decision tree primarily use?**

A) Sepal length
B) Sepal width
C) Petal length
D) Petal width

**Answer:** C) Petal length

**Explanation:** Our decision tree uses petal length as the main feature with thresholds at 2.5 and 4.8 to classify iris species.

---

### Question 5: Distance Calculation

**In KNN, what does Euclidean distance measure?**

A) The time between measurements
B) The similarity between feature vectors
C) The accuracy of predictions
D) The size of the dataset

**Answer:** B) The similarity between feature vectors

**Explanation:** Euclidean distance measures how similar two data points are by calculating the straight-line distance between them in feature space.

---

## 🎯 Post-Workshop Assessment (15 minutes)

### Question 6: Linear Regression

**In the equation y = mx + b, what does 'm' represent in our house price model?**

A) The base price of any house
B) The price increase per square foot
C) The total price
D) The house size

**Answer:** B) The price increase per square foot

**Explanation:** The slope (m) represents how much the price increases for each additional square foot.

---

### Question 7: Model Comparison

**Which statement about KNN vs Decision Trees is correct?**

A) KNN is always more accurate
B) Decision Trees are always faster
C) KNN uses similar examples, Decision Trees use explicit rules
D) They always give the same predictions

**Answer:** C) KNN uses similar examples, Decision Trees use explicit rules

**Explanation:** KNN is instance-based (uses similar examples) while Decision Trees are rule-based (use explicit decision rules).

---

### Question 8: Practical Application

**You want to classify emails as spam or not spam. Which type of machine learning is this?**

A) Regression
B) Classification
C) Clustering
D) Dimensionality Reduction

**Answer:** B) Classification

**Explanation:** Spam detection involves predicting categories (spam vs not spam), which is a classification problem.

---

### Question 9: JavaScript AI Implementation

**What is an advantage of implementing AI in JavaScript?**

A) JavaScript is the fastest language for AI
B) JavaScript has the most AI libraries
C) JavaScript runs in browsers without installation
D) JavaScript uses less memory

**Answer:** C) JavaScript runs in browsers without installation

**Explanation:** JavaScript's main advantage for educational AI is accessibility - it runs in any web browser without requiring software installation.

---

### Question 10: Real-world Applications

**Which of these is NOT a typical use case for the algorithms we learned?**

A) Recommendation systems
B) Medical diagnosis decision support
C) Stock price prediction
D) Creating artificial images

**Answer:** D) Creating artificial images

**Explanation:** Image generation typically requires more complex algorithms like GANs or diffusion models, not the basic algorithms we covered.

---

## 🧠 Advanced Thinking Questions

### Question 11: Critical Thinking

**A student gets different predictions from KNN and Decision Tree for the same iris flower. Explain why this might happen and which prediction might be more reliable.**

**Sample Answer:** This happens because the algorithms work differently:

- KNN looks at the most similar training examples
- Decision Tree uses fixed rules based on petal length

The more reliable prediction depends on:

- Quality and quantity of training data
- Whether the new flower fits the decision tree's rules well
- How representative the nearest neighbors are

Neither is always better - it depends on the specific case and data quality.

---

### Question 12: Problem Solving

**You're building a system to predict student grades based on study hours. Your linear regression model predicts negative grades for very low study hours. How would you improve this?**

**Sample Answer:** Several approaches:

1. **Add constraints:** Ensure predictions can't go below 0
2. **Use more features:** Include attendance, previous grades, etc.
3. **Try non-linear models:** Relationship might not be perfectly linear
4. **Better data preprocessing:** Remove outliers, normalize data
5. **Use a different algorithm:** Maybe classification (A/B/C/D/F grades) instead

---

## 📊 Quiz Scoring Guide

### Scoring Rubric

- **Questions 1-5:** 1 point each (Pre/Mid workshop - 5 points total)
- **Questions 6-10:** 2 points each (Post workshop - 10 points total)
- **Questions 11-12:** 5 points each (Advanced thinking - 10 points total)

**Total possible points:** 25

### Performance Levels

- **23-25 points:** Excellent understanding
- **18-22 points:** Good understanding
- **13-17 points:** Basic understanding
- **Below 13:** Needs review

### Instructor Notes

- Use Questions 1-5 to gauge starting knowledge
- Questions 6-10 test core workshop concepts
- Questions 11-12 assess deeper understanding
- Encourage discussion of answers
- Use incorrect answers as learning opportunities

---

## 🎓 Answer Key Summary

1. C - ML learns patterns vs explicit rules
2. B - Regression for continuous values
3. B - KNN uses similar examples
4. C - Decision tree uses petal length
5. B - Euclidean distance measures similarity
6. B - Slope is price per square foot
7. C - KNN uses examples, DT uses rules
8. B - Spam detection is classification
9. C - JavaScript runs in browsers
10. D - Image generation needs complex models

**Advanced Questions:** Open-ended with sample answers provided for guidance.
