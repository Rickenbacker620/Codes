import fs from "fs";

try {
    let content = await fs.promises.readFile("./input.txt", "utf-8");
    console.log(content);
} catch (err) {
    console.error(err);
}

fs.promises
    .readFile("./input.txt", "utf-8")
    .then((content) => console.log(content))
    .catch((err) => console.error(err));
