// script.js
function downloadFile(filename) {
    // Create a link element
    const link = document.createElement('a');
    
    // Set the href attribute to the file path
    link.href = filename;
    
    // Set the download attribute to force download
    link.download = filename;
    
    // Append the link to the body (required for Firefox)
    document.body.appendChild(link);
    
    // Trigger the download by simulating a click
    link.click();
    
    // Remove the link from the document
    document.body.removeChild(link);
}