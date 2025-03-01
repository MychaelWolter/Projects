document.addEventListener("DOMContentLoaded", () => {
    const fadeIn = [...document.querySelectorAll(".fade-in")];

    setTimeout(() => {
        fadeIn.map((item) => {
            item.classList.add("visible");
        });
    },100);
});