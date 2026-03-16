// Import AI models
import { createPretrainedIrisClassifiers } from "./ml-classification-lab.js";
import { createHousePricePredictor } from "./SimpleLinearRegression.js";

// Global variables for workshop
let knn, decisionTree, regression;
let workshopStartTime;

// Initialize workshop when page loads
document.addEventListener("DOMContentLoaded", function () {
  initializeWorkshop();
  startWorkshopTimer();
});

// Initialize AI models
function initializeWorkshop() {
  console.log("🎓 Welcome to AI for IT Students and Professionals Workshop!");

  // Create classification models
  const classifiers = createPretrainedIrisClassifiers();
  knn = classifiers.knn;
  decisionTree = classifiers.decisionTree;

  // Create regression model
  regression = createHousePricePredictor();

  // Make models globally accessible for console experimentation
  window.knn = knn;
  window.decisionTree = decisionTree;
  window.regression = regression;

  console.log("✅ AI models initialized successfully!");
  console.log(
    "💡 Tip: Open browser console (F12) to experiment with the models directly",
  );

  // Log model info
  console.log("📊 Available models:");
  console.log("- window.knn: K-Nearest Neighbors classifier");
  console.log("- window.decisionTree: Decision Tree classifier");
  console.log("- window.regression: Linear Regression model");
}

// Start workshop countdown timer
function startWorkshopTimer() {
  workshopStartTime = Date.now();
  const timerElement = document.getElementById("timer");
  const workshopDuration = 45 * 60 * 1000; // 45 minutes in milliseconds

  const timerInterval = setInterval(() => {
    const elapsed = Date.now() - workshopStartTime;
    const remaining = Math.max(0, workshopDuration - elapsed);

    const minutes = Math.floor(remaining / 60000);
    const seconds = Math.floor((remaining % 60000) / 1000);

    timerElement.textContent = `Workshop Time: ${minutes
      .toString()
      .padStart(2, "0")}:${seconds.toString().padStart(2, "0")}`;

    if (remaining === 0) {
      clearInterval(timerInterval);
      timerElement.textContent = "Workshop Complete! 🎉";
      timerElement.style.color = "#27ae60";
    }
  }, 1000);
}

// Predict iris flower species using KNN
window.predictWithKNN = function () {
  const sepalLength = parseFloat(document.getElementById("sepalLength").value);
  const sepalWidth = parseFloat(document.getElementById("sepalWidth").value);
  const petalLength = parseFloat(document.getElementById("petalLength").value);
  const petalWidth = parseFloat(document.getElementById("petalWidth").value);

  const features = [sepalLength, sepalWidth, petalLength, petalWidth];

  try {
    const prediction = knn.predict(features);
    const resultElement = document.getElementById("classificationResult");
    resultElement.innerHTML = `🌸 KNN Prediction: <strong>${prediction}</strong>`;

    // Log to console for learning
    console.log(`🔍 KNN Analysis:`);
    console.log(`Input features: [${features.join(", ")}]`);
    console.log(`Predicted species: ${prediction}`);

    // Show which features are most important
    if (petalLength <= 2.5) {
      console.log(
        `💡 Key insight: Small petal length (${petalLength}) strongly suggests Setosa`,
      );
    } else if (petalLength <= 4.8) {
      console.log(
        `💡 Key insight: Medium petal length (${petalLength}) suggests Versicolor`,
      );
    } else {
      console.log(
        `💡 Key insight: Large petal length (${petalLength}) suggests Virginica`,
      );
    }
  } catch (error) {
    document.getElementById("classificationResult").innerHTML =
      `❌ Error: ${error.message}`;
  }
};

// Predict iris flower species using Decision Tree
window.predictWithDecisionTree = function () {
  const sepalLength = parseFloat(document.getElementById("sepalLength").value);
  const sepalWidth = parseFloat(document.getElementById("sepalWidth").value);
  const petalLength = parseFloat(document.getElementById("petalLength").value);
  const petalWidth = parseFloat(document.getElementById("petalWidth").value);

  const features = [sepalLength, sepalWidth, petalLength, petalWidth];

  try {
    const prediction = decisionTree.predict(features);
    const resultElement = document.getElementById("classificationResult");
    resultElement.innerHTML = `🌳 Decision Tree Prediction: <strong>${prediction}</strong>`;

    // Log decision path
    console.log(`🌳 Decision Tree Analysis:`);
    console.log(`Input features: [${features.join(", ")}]`);
    console.log(`Using petal length: ${petalLength}`);

    if (petalLength <= 2.5) {
      console.log(`Decision: ${petalLength} <= 2.5 → Setosa`);
    } else if (petalLength <= 4.8) {
      console.log(`Decision: 2.5 < ${petalLength} <= 4.8 → Versicolor`);
    } else {
      console.log(`Decision: ${petalLength} > 4.8 → Virginica`);
    }
  } catch (error) {
    document.getElementById("classificationResult").innerHTML =
      `❌ Error: ${error.message}`;
  }
};

// Predict house price using Linear Regression
window.predictHousePrice = function () {
  const houseSize = parseFloat(document.getElementById("houseSize").value);

  try {
    const predictedPrice = regression.predict(houseSize);
    const resultElement = document.getElementById("regressionResult");
    resultElement.innerHTML = `🏠 Predicted Price: <strong>$${Math.round(
      predictedPrice * 1000,
    ).toLocaleString()}</strong>`;

    // Show regression equation and data
    const params = regression.getParameters();
    const dataElement = document.getElementById("regressionData");
    dataElement.textContent = `
📈 Linear Regression Model:
${params.equation}

Input: ${houseSize} sq ft
Output: $${Math.round(predictedPrice * 1000).toLocaleString()}

Model Parameters:
- Slope: ${params.slope.toFixed(4)} (price increase per sq ft)
- Intercept: ${params.intercept.toFixed(2)} (base price)
    `;

    // Log to console
    console.log(`📈 Regression Analysis:`);
    console.log(`House size: ${houseSize} sq ft`);
    console.log(
      `Predicted price: $${Math.round(predictedPrice * 1000).toLocaleString()}`,
    );
    console.log(`Model equation: ${params.equation}`);
  } catch (error) {
    document.getElementById("regressionResult").innerHTML =
      `❌ Error: ${error.message}`;
  }
};

// Show advanced console commands for experimentation
window.showAdvancedConsoleCommands = function () {
  const commandsDiv = document.getElementById("consoleCommands");
  commandsDiv.style.display =
    commandsDiv.style.display === "none" ? "block" : "none";

  if (commandsDiv.style.display === "block") {
    console.log(`
🧪 Advanced Workshop Commands:

// Test KNN with custom data
window.knn.predict([5.0, 3.0, 1.6, 0.2]);

// Test Decision Tree
window.decisionTree.predict([6.0, 3.0, 4.0, 1.0]);

// Test Regression
window.regression.predict(2500);

// Get model parameters
console.log(window.regression.getParameters());

// Add more training data to KNN
window.knn.train(
  [[5.0, 3.0, 1.6, 0.2], [6.9, 3.1, 4.9, 1.5], [6.5, 3.0, 5.8, 2.2]],
  ["setosa", "versicolor", "virginica"]
);

// Create a new regression model
import { SimpleLinearRegression } from './SimpleLinearRegression.js';
const newRegression = new SimpleLinearRegression();
newRegression.train([1, 2, 3, 4, 5], [2, 4, 6, 8, 10]);
console.log(newRegression.predict(6)); // Should predict 12
    `);
  }
};

// Workshop completion tracker
const completedSections = new Set();

function markSectionComplete(sectionName) {
  completedSections.add(sectionName);
  console.log(`✅ Section completed: ${sectionName}`);

  if (completedSections.size >= 3) {
    console.log("🎉 Congratulations! You have completed the AI workshop!");
    console.log("📚 Continue learning with the provided resources.");
  }
}

// Track when users interact with different parts
document.addEventListener("click", function (event) {
  if (event.target.tagName === "BUTTON") {
    const buttonText = event.target.textContent;

    if (buttonText.includes("KNN") || buttonText.includes("Decision Tree")) {
      markSectionComplete("Classification");
    } else if (buttonText.includes("House Price")) {
      markSectionComplete("Regression");
    } else if (buttonText.includes("Console Commands")) {
      markSectionComplete("Advanced Experimentation");
    }
  }
});

// Initialize workshop message
console.log(`
🎓 AI Workshop for IT Students and Professionals
==============================================

Welcome to your 45-minute journey into AI and Machine Learning!

What you'll learn:
✨ Classification with K-Nearest Neighbors
✨ Decision Trees for rule-based predictions  
✨ Linear Regression for numerical predictions
✨ Hands-on JavaScript implementation

Tips:
💡 Try different input values in the web interface
💡 Open the browser console (F12) to see detailed analysis
💡 Experiment with the models using the console commands
💡 Ask questions and explore!

Let's start building AI! 🚀
`);
