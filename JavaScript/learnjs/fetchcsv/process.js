
cchart();

async function getData() {
  let years = [];
  let temps = [];
  const response = await fetch("ZonAnn.Ts+dSST.csv");
  const data = await response.text();
  const rows = data.split("\n").slice(1, -1);
  rows.forEach((e) => {
    res = e.split(",");
    years.push(res[0]);
    temps.push(parseFloat(res[1]) + 14);
  });
  return {years, temps};
}

async function cchart() {
  const data = await getData();
  let ctx = document.getElementById("chart").getContext("2d");
  let chart = new Chart(ctx, {
    type: "line",
    data: {
      labels: data.years,
      datasets: [
        {
          label: "# of Votes",
          data: data.temps,
          backgroundColor: ["rgba(255, 99, 132, 0.2)"],
          bordercolor: ["rgba(255, 99, 132, 0.2)"],
          borderWidth: 1,
        },
      ],
    },
    options: {
      scales: {
        yAxes: [
          {
            ticks: {
              beginAtZero: false,
            },
          },
        ],
      },
    },
  });
}
