const loadElement = document.querySelector("[data-preloader]");

window.addEventListener("load", () => {
    loadElement.classList.add("loaded");
});