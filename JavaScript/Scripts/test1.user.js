let panel = window.frames["bottomFrame"]["mainFrame"].document;
Array.from(panel.getElementsByTagName("input"))
  .filter((e) => e.value == "5_0.95")
  .forEach((e) => e.click());
panel.getElementsByName("zgpj")[0].value = "教学认真负责";
panel.getElementsByTagName('img')[1].click();